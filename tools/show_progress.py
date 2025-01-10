from pathlib import Path

from os.path import curdir

if __name__ == '__main__':
    print('\n')
    def get_number(name, f):
        i = 0
        while i < len(name) and not '0' <= name[i] <= '9': i += 1
        j = i + 1
        while j < len(name) and '0' <= name[j] <= '9': j += 1
        return int(name[i:j])
    ignores = set([])
    leetcodepath = Path('../')
    donecnt, tocnt = 0, 0
    sessions = [f for f in leetcodepath.iterdir() if f.is_dir() and f.name.startswith('session')]
    for session in sessions:
        problems = [f for f in session.iterdir() if f.name.startswith('problem')]
        for problem in problems:
            fs = [get_number(f.name, f) for f in problem.iterdir() if f.name.endswith('.cpp')]
            absents = []
            start = int(problem.name[len('problem'):]) - 99
            if len(fs) < 100:
                for i in range(start, start + 100):
                    if i not in fs and i not in ignores:
                        absents.append(i)
            donecnt += len(fs)
            tocnt += len(absents)
            print(f'{problem}, tocnt: {len(absents)}, {absents if len(absents) <= 10 else absents[:10]}')
    print(f'done: {donecnt}, todo: {tocnt}')