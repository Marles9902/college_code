import math
import random
import time
import matplotlib.pyplot as plt

# ******************** constants: BEGIN ********************
N_DAYS_IN_YEAR = 365
N_CLASS_SIZE = 23
N_SIMULATIONS = 100
# ******************** constants: END ********************

def is_sorted(l):
    n = len(l)

    if n == 1:
        return True

    for i in range(n-1): # since we compare indices i and i+1, we range from 0 to len(l)-1
        if l[i] > l[i+1]:
            return False 

    return True


def str_to_list(s):
    """
    This function converts a string to a list of chars (in case we want to modify the list somehow)
    """
    return [s[i] for i in range(len(s))] if type(s) is str else s.copy()


def to_lcase(l):
    """
    This function only convert char elements in the list to lower-case.
    Obviously, non-char elements will not be affected.
    """
    l_lcase = str_to_list(l)

    for i in range(len(l_lcase)):
        if type(l_lcase[i]) is str:
            l_lcase[i] = l_lcase[i].lower()

    return l_lcase


def is_anagram(l1, l2, normalize_char_case=True):
    """
    Normally anagrams are based on words only.
    But this function supports numeric lists as anagrams, as well..
    """

    n1 = len(l1)
    n2 = len(l2)

    # we can short-circuit when the lengths are unequal
    if n1 != n2:
        return False

    # we normally disregard case when considering char anagrams
    if normalize_char_case:
        l1 = to_lcase(l1)   # but remember, the to_lcase() leaves non-char elements alone
        l2 = to_lcase(l2)
    else: # in case strings and we don't want to normalize to lcase
        l1 = str_to_list(l1)
        l2 = str_to_list(l2)

    # here we sort each list
    #   this greatly simplifies the problem compared to not sorting
    if not is_sorted(l1):
        l1 = sorted(l1)
    if not is_sorted(l2):
        l2 = sorted(l2)

    # because the two lists are sorted, we can now short-circuit (exit the loop) when we encounter the first mismatch
    for i in range(n1):
        if l1[i] != l2[i]:
            return False
    
    # if we made it this far then the two lists are necessarily the same length and have the same elements (unless case matters, FOR STRINGS, and case differs for some element)
    return True


def has_duplicates(l, disregard_char_case=False):
    n = len(l)

    # a 0 or single element list is already implicitly sorted, so we can short-circuit
    if n < 2:
        return False

    if not disregard_char_case:
        l = to_lcase(l)
    else: # in case string and we don't want to normalize to lcase
        l = str_to_list(l)

    # here we sort the list
    #   this greatly simplifies the problem compared to not sorting
    if not is_sorted(l):
        l = sorted(l)

    # because the list is sorted, we can now short-circuit (exit the loop) when we encounter the first matching adjacent pair of elements
    for i in range(n-1):
        if l[i] == l[i+1]:
            return True

    return False


def run_bd_paradox_sim(n_sims, n_class_size=N_CLASS_SIZE, is_leap_year=False):
    print(f"Running {n_sims} Birthday Paradox simulations on a class size of {n_class_size} students...")
    p = 0
    n_dups = 0
    # fig = plt.figure(figsize=(8,4))
    # x = []
    # y = []
    for i_sim in range(n_sims):
        l_birthdays = [random.randint(1, N_DAYS_IN_YEAR + (1 if is_leap_year else 0)) for i in range(n_class_size)]
        n_dups += 1 if has_duplicates(l_birthdays) else 0
        # x.append(i_sim)
        # y.append(n_dups / (i_sim+1))
    p = n_dups / n_sims
    print(f"\tDONE!\nThe probability that at least 2 students from a class size of {n_class_size} have the same birthday converged to {p} after {n_sims} simulations.")
    # plt.plot(x, y)
    # plt.show()


def remove_duplicates(l):
    l = str_to_list(l)  # in case l is a string

    n = len(l)

    # a 0 or single element list is already implicitly sorted, so we can short-circuit
    if n < 2:
        return l

    # here we sort the list
    #   this greatly simplifies the problem compared to not sorting
    if not is_sorted(l):
        l = sorted(l)

    l_dups_removed = []
    
    # iterate from index 0 to len(l)-1
    #   only add the last non-repeating element, which we can do since the list has been sorted
    for i in range(n-1):
        if l[i] != l[i+1]:
            l_dups_removed.append(l[i])

    # but we still have the very last index to add
    #   this works since if there was a dup at the n-2 index, it will not have been added to l_dups_removed
    l_dups_removed.append(l[n-1])

    return l_dups_removed


def words_file_to_list(fname, use_list_append=True):
    l_words = []

    try:
        with open(fname, 'r') as f_words:
            for words_line in f_words:
                for word in words_line.split():
                    if use_list_append:
                        l_words.append(word.strip()) # dynamically resizes 
                    else:
                        l_words += [word] # adding to separate lists (which exist in two different places in memory)
            f_words.close()
    except Exception as e:
        print(f"words_file_to_list: ***RUNTIME ERROR caught***: {e}")

    return l_words

def benchmark_words_file_to_list(fname, use_list_append):
    s_append_list_mechanic = ("t += [x] idiom" if not use_list_append else "List.append() method")
    print(f"Benchmarking '{fname}' file to words list (using {s_append_list_mechanic})")

    # timestamp for start of the execution of words_file_to_list()
    t0 = time.time()

    # execute words_file_to_list()
    l_words = words_file_to_list(fname)

    # timestamp for end of the execution of words_file_to_list()
    t1 = time.time()

    # the delta is just the elapsed time
    t_delta = t1 - t0

    print(f"\ttime elapsed (using {s_append_list_mechanic}): {t_delta} seconds") # CPU seconds elapsed (floating point)

    return t_delta, l_words




# **************************************** main body (simply calls main() when this py file is exec'ed from bash): BEGIN ****************************************
if __name__ == '__main__':
    # print(is_sorted([1,2,2]))
    # print(is_sorted(['b','a']))
    # print(is_sorted(['b','a','b']))

    # print(is_anagram("never", "REven"))
    # print(is_anagram("steve", "STEVEN"))

    # print(has_duplicates([1,2,3]))
    # print(has_duplicates([1,2,1]))
    # print(has_duplicates(['a','b','c']))
    # print(has_duplicates(['a','b','a']))
    # print(has_duplicates(["steven", "steve"]))
    # print(has_duplicates(["steven", "steven"]))
    # print(has_duplicates([0]))

    # for p in range(1,6):
    #     run_bd_paradox_sim(10**p, n_class_size=N_CLASS_SIZE, is_leap_year=False)

    # print("steven", remove_duplicates("steven"))




    tdelta__list_append, l_words = benchmark_words_file_to_list("mobysmall.txt", use_list_append=True)
    print()
    tdelta__add_list_idiom, l_words = benchmark_words_file_to_list("mobysmall.txt", use_list_append=False)

    # the rest of this code is just for formatting the summary output
    s_mech = ""
    eff_factor = 0
    if tdelta__add_list_idiom < tdelta__list_append:
        s_mech = "t += [x] idiom"
        eff_factor = tdelta__list_append / tdelta__add_list_idiom
    else:
        s_mech = "List.append() method"
        eff_factor = tdelta__add_list_idiom / tdelta__list_append
    s_efficiency = f"{s_mech} is {eff_factor} more efficient!"
    print(f"\n{s_efficiency}\n\n{l_words}")
    print(f"\n{s_efficiency}")

    pass
    
    
# **************************************** main body (simply calls main() when this py file is exec'ed from bash): END ****************************************