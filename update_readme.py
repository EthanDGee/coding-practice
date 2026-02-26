import os
import re


def format_name(name):
    """Converts kebab-case or snake_case to Title Case."""
    return " ".join(word.capitalize() for word in re.split("[-_]", name))


def get_solutions():
    """Gets all solutions for every language"""
    solutions_dir = "solutions"
    if not os.path.exists(solutions_dir):
        return {}

    languages = {}
    # Iterate through language directories (e.g., bash, cpp)
    for lang in sorted(os.listdir(solutions_dir)):
        lang_path = os.path.join(solutions_dir, lang)
        if not os.path.isdir(lang_path):
            continue

        problems = []
        # Iterate through problem directories (e.g., hello-world)
        for problem in sorted(os.listdir(lang_path)):
            problem_path = os.path.join(lang_path, problem)
            if not os.path.isdir(problem_path):
                continue

            # Check for versioned subdirectories (e.g., 1, 2)
            versions = [
                v
                for v in os.listdir(problem_path)
                if os.path.isdir(os.path.join(problem_path, v)) and v.isdigit()
            ]
            if versions:
                # Use the latest version for the link
                latest_version = max(versions, key=int)
                link_path = os.path.join(problem_path, latest_version)
            else:
                link_path = problem_path

            problems.append({"name": format_name(problem), "path": link_path})

        if problems:
            # Special handling for common language names
            display_name = lang.capitalize()
            if lang.lower() == "cpp":
                display_name = "C++"

            languages[display_name] = problems

    return dict(sorted(languages.items()))


def generate_readme(languages):
    """Generates the README.md with Exercism info"""

    lines = ["# Coding Practive", ""]
    lines.append(
        "My solutions to various Exercism problems across different programming languages."
    )
    lines.append("")

    total_solved = sum(len(problems) for problems in languages.values())
    lines.append(f"**Total Problems Solved: {total_solved}**")
    lines.append("")

    for lang, problems in languages.items():
        lines.append(f"## {lang}")
        for problem in problems:
            # Ensure path uses forward slashes for Markdown links
            relative_path = problem["path"].replace(os.sep, "/")
            lines.append(f"- [{problem['name']}]({relative_path})")
        lines.append("")  # Add a newline after each language section

    return "\n".join(lines)


def main():
    languages = get_solutions()
    if not languages:
        print("No solutions found in 'solutions/' directory.")
        return

    readme_content = generate_readme(languages)
    with open("README.md", "w") as f:
        f.write(readme_content)
    print("README.md updated successfully.")


if __name__ == "__main__":
    main()
