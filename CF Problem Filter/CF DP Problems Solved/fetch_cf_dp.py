"""Download accepted Codeforces problems for one handle (no external packages needed).

Run: python fetch_cf_dp.py
Outputs: cf_all_solved.csv, cf_dp_solved.csv, cf_all_solved_ids.txt
"""
import csv
import json
import time
from urllib.error import HTTPError, URLError
from urllib.parse import urlencode
from urllib.request import Request, urlopen

HANDLE = "Uzzam_Hazrat"
PAGE_SIZE = 1000
API_URL = "https://codeforces.com/api/user.status"


def fetch_page(start):
    params = urlencode({"handle": HANDLE, "from": start, "count": PAGE_SIZE})
    url = f"{API_URL}?{params}"
    for attempt in range(4):
        try:
            req = Request(url, headers={"User-Agent": "Mozilla/5.0 (compatible; CF-DP-Tracker/1.0)", "Accept": "application/json"})
            with urlopen(req, timeout=40) as response:
                data = json.load(response)
            if data.get("status") == "OK":
                return data["result"]
            raise RuntimeError(data.get("comment", "Unknown Codeforces API error"))
        except (HTTPError, URLError, TimeoutError, OSError, ValueError, RuntimeError) as exc:
            print(f"API attempt {attempt + 1}/4 failed: {exc}")
            if attempt == 3:
                raise RuntimeError(
                    "Could not access Codeforces API. Test this in your browser:\n"
                    f"  {url}\n"
                    "If you see HTTP 403 or Cloudflare, retry later or on another network."
                ) from exc
            time.sleep(3 * (attempt + 1))


def problem_key(p):
    cid = p.get("contestId")
    index = p.get("index", "")
    if cid is not None and index:
        return f"{cid}{index}"
    return f"{p.get('problemsetName', 'unknown')}:{index}:{p.get('name', '')}"


def problem_url(p):
    cid, index = p.get("contestId"), p.get("index")
    if cid is None or not index:
        return ""
    if cid >= 100000:
        return f"https://codeforces.com/gym/{cid}/problem/{index}"
    return f"https://codeforces.com/problemset/problem/{cid}/{index}"


def write_csv(filename, rows):
    with open(filename, "w", newline="", encoding="utf-8-sig") as f:
        writer = csv.DictWriter(f, fieldnames=["problem_id", "name", "rating", "tags", "url"])
        writer.writeheader()
        writer.writerows(rows)


def main():
    solved = {}
    start = 1
    submission_count = 0
    while True:
        print(f"Fetching submissions {start} to {start + PAGE_SIZE - 1}...")
        batch = fetch_page(start)
        submission_count += len(batch)
        for sub in batch:
            if sub.get("verdict") != "OK":
                continue
            p = sub.get("problem") or {}
            if not p:
                continue
            key = problem_key(p)
            tags = p.get("tags") or []
            solved[key] = {
                "problem_id": key,
                "name": p.get("name", ""),
                "rating": p.get("rating", ""),
                "tags": ", ".join(tags),
                "url": problem_url(p),
            }
        if len(batch) < PAGE_SIZE:
            break
        start += PAGE_SIZE
        time.sleep(2.3)  # Codeforces API allows at most one call per 2 seconds.

    all_rows = sorted(solved.values(), key=lambda r: r["problem_id"])
    dp_rows = [r for r in all_rows if "dp" in [t.strip().lower() for t in r["tags"].split(",")]]
    write_csv("cf_all_solved.csv", all_rows)
    write_csv("cf_dp_solved.csv", dp_rows)
    with open("cf_all_solved_ids.txt", "w", encoding="utf-8") as f:
        f.write("\n".join(row["problem_id"] for row in all_rows) + "\n")
    print(f"\nFetched {submission_count} submissions.")
    print(f"Unique accepted problems: {len(all_rows)}")
    print(f"Accepted problems tagged dp: {len(dp_rows)}")
    print("Saved: cf_all_solved.csv, cf_dp_solved.csv, cf_all_solved_ids.txt")
    print("Upload cf_all_solved.csv here so I can exclude ALL already solved problems.")


if __name__ == "__main__":
    main()
