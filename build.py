from os import system, walk, getcwd
from os.path import join

path_to_files = []

for dirpath, dirnames, filenames in walk(getcwd()):
    for f in filenames:
        if f.endswith(".c"):
            path_to_files.append(join(dirpath, f))

system("gcc " + " ".join(path_to_files))