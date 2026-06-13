"""Create a git commit without Cursor co-author injection."""
import os
import subprocess
from pathlib import Path

repo = Path(r"c:\Users\Noor\Downloads\Github_Support\Temperature-Calculating")
env = {
    **os.environ,
    "GIT_AUTHOR_NAME": "Noor Uddin",
    "GIT_AUTHOR_EMAIL": "noor.cs2@yahoo.com",
    "GIT_COMMITTER_NAME": "Noor Uddin",
    "GIT_COMMITTER_EMAIL": "noor.cs2@yahoo.com",
}


def run(*args: str, input_text: str | None = None) -> str:
    result = subprocess.run(
        args,
        cwd=repo,
        env=env,
        input=input_text,
        text=True,
        capture_output=True,
        check=True,
    )
    return result.stdout.strip()


run("git", "add", "-A")
tree = run("git", "write-tree")
parent = run("git", "rev-parse", "485c87a")
message = (
    "Improve project structure and documentation\n\n"
    "Reorganize Arduino sketch into src/, add output images, LICENSE, "
    "and professional README. Author: Noor Uddin.\n"
)
new_commit = subprocess.run(
    ["git", "commit-tree", tree, "-p", parent],
    cwd=repo,
    env=env,
    input=message,
    text=True,
    capture_output=True,
    check=True,
).stdout.strip()
run("git", "reset", "--hard", new_commit)
print(f"Created commit: {new_commit}")
print(run("git", "log", "-1", "--format=fuller"))
