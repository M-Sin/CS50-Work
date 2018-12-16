# helper functions for a plagiarism detection program
# takes in two text files and returns an array of various similarities between them

from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""
    a_set = list(set(a.split("\n"))) # split input large string into lines, change to set
    b_set = list(set(b.split("\n"))) # to get rid of duplicates, then back to list and sort it
    a_set.sort() # sort the lists to prevent O(n^2) time complexity
    b_set.sort()
    similarities = []
    for line_a in range(len(a_set)): # for each element in first list
        for line_b in range(len(b_set)): # for each element in second list
            if a_set[line_a] == b_set[line_b]: # if that element is equal, add to similarities list
                similarities.append(b_set[line_b])
            if a_set[line_a] < b_set[line_b]: # if we have passed the point where we will no longer find a match because they are sorted
                break # end loop
    # if element of list a is not element of list b then iterate over next element(s) in loop(s)
    return (similarities)


def sentences(a, b):
    """Return sentences in both a and b"""
    a_set = list(set(sent_tokenize(a))) # split input large string into sentences, change to set
    b_set = list(set(sent_tokenize(b))) # to get rid of duplicates, then back to list and sort it
    a_set.sort() # sort the lists to prevent O(n^2) time complexity
    b_set.sort()
    similarities = []
    for line_a in range(len(a_set)): # for each element in first list
        for line_b in range(len(b_set)): # for each element in second list
            if a_set[line_a] == b_set[line_b]: # if that element is equal, add to similarities list
                similarities.append(b_set[line_b])
            if a_set[line_a] < b_set[line_b]: # if we have passed the point where we will no longer find a match because they are sorted
                break # end loop
    # if element of list a is not element of list b then iterate over next element(s) in loop(s)
    return (similarities)


def subsplit(inp,n):
    """ substring helper function """
    split_a = [] # create list
    if n>len(inp): # if substrings is larger than input string, no possible matches, return empty list
        return (split_a)
    for var in range(len(inp)): # for each n substrings
        if len(inp[var:var+n])==n:  # excludes cases where the algorithm would try to run off the string
            split_a.append(inp[var:var+n]) # append substring to list
    split_set = list(set(split_a)) # turn into set to remove duplicates, then back to list
    split_set.sort() # sort, duh
    return (split_set)

def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    a_set = subsplit(a,n) # create first substring list
    b_set = subsplit(b,n) # create second substring list
    similarities = []
    for line_a in range(len(a_set)): # for each element in first list
        for line_b in range(len(b_set)): # for each element in second list
            if a_set[line_a] == b_set[line_b]: # if that element is equal, add to similarities list
                similarities.append(b_set[line_b])
            if a_set[line_a] < b_set[line_b]: # if we have passed the point where we will no longer find a match because they are sorted
                break # end loop
    # if element of list a is not element of list b then iterate over next element(s) in loop(s)
    return (similarities)