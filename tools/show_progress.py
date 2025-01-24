from pathlib import Path

# if __name__ == '__main__':
#     print('\n')
#     def get_number(name, f):
#         i = 0
#         while i < len(name) and not '0' <= name[i] <= '9': i += 1
#         j = i + 1
#         while j < len(name) and '0' <= name[j] <= '9': j += 1
#         return int(name[i:j])
#     ignores = set([])
#     leetcodepath = Path('../')
#     donecnt, tocnt = 0, 0
#     sessions = [f for f in leetcodepath.iterdir() if f.is_dir() and f.name.startswith('session')]
#     for session in sessions:
#         problems = [f for f in session.iterdir() if f.name.startswith('problem')]
#         for problem in problems:
#             fs = [get_number(f.name, f) for f in problem.iterdir() if f.name.endswith('.cpp')]
#             absents = []
#             start = int(problem.name[len('problem'):]) - 99
#             if len(fs) < 100:
#                 for i in range(start, start + 100):
#                     if i not in fs and i not in ignores:
#                         absents.append(i)
#             donecnt += len(fs)
#             tocnt += len(absents)
#             print(f'{problem}, tocnt: {len(absents)}, {absents if len(absents) <= 10 else absents[:10]}')
#     print(f'done: {donecnt}, todo: {tocnt}')

if __name__ == '__main__':
    def get_number(name, f):
        i = 0
        while i < len(name) and not '0' <= name[i] <= '9': i += 1
        j = i + 1
        while j < len(name) and '0' <= name[j] <= '9': j += 1
        return int(name[i:j])
    ignores = set([
        3004, 3009, 3018, 3023, # plus
        3050, 3051, 3052, 3053, 3054, 3055, 3056, 3057, 3058, 3059, 3060, 3061, 3087, 3089,
        3103, 3118, 3124, 3126, 3140, 3150, 3156, 3166, 3172, 3182, 3188, 3198,
        3204, 3214, 3220, 3230, 3236, 3246, 3252, 3262, 3268, 3278, 3293,
        3308, 3322, 3328, 3338, 3358, 3368, 3374, 3384, 3390,
        3401, # pandas
        3415, 3416, 3421, 3422 # plus
    ])
    leetcodepath = Path('../')
    total = 0
    todo = 0
    done = 0
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
            todo += len(absents)
            total += 100
            done += len(fs)
            print(problem, start, len(absents), 'Done' if not absents else absents if len(absents) <= 10 else absents[:10])
    print(f'total: {total}, todo: {todo}, done: {done}, ignore: {len(ignores)}')
