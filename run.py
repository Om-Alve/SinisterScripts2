import argparse
import re
import os
import sys

def transform_code(file_path):
    with open(file_path, 'r') as file:
        code = file.read()
    code = '\n'.join(list(reversed(code.split('\n'))))

    keyword_replacements = {
        "conjure": "def",
        "coven": "class",
        "summon": "input",
        "reap": "return",
        "scream": "print",
        "haunt": "for",
        "lurk": "while",
        "dread": "if",
        "curse": "else",
        "tempt": "try",
        "ward": "except",
        "relent": "pass",
        "shatter": "break",
        "persist": "continue",
        "unholy": "True",
        "blessed": "False",
        "void": "None",
        "conjoin": "and",
        "disjoin": "or",
        "negate": "not"
    }

    for keyword in keyword_replacements.values():
        if re.search(r'\b{}\b'.format(keyword), code):
            print(f"Error: The keyword '{keyword}' is present in the code.")
            sys.exit(1)

    for word, replacement in keyword_replacements.items():
        code = re.sub(r"\b{}\b".format(word), replacement, code)

    return code
def execute_file(file_path):
    transformed_code = transform_code(file_path)

    temp_file_path = "temp_spooky.py"
    with open(temp_file_path, 'w') as file:
        file.write(transformed_code)

    os.system("python " + temp_file_path)

    os.remove(temp_file_path)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Transform and execute Python files with spooky transformations.")
    parser.add_argument("file", help="The Python file to transform and execute.")
    args = parser.parse_args()

    if not os.path.isfile(args.file):
        print(f"Error: {args.file} is not a valid file path.")
        sys.exit(1)

    execute_file(args.file)