# Sequence-Alignment

The Sequence Alignment problem is one of the fundamental problems of Biological Sciences, aimed at finding the similarity of two amino-acid sequences.


### Problem description:

Given two strings, S and T, the alignment of the two is calculated by inserting a number of spaces between the characters of each string and figuring out the penalty of the modified strings.

For characters s in S and t in T with index i, the alignment’s penalty is calculated as:
- A penalty of p_gap occurs if either s or t is a space character.
- A penalty of p_miss occurs if s != t.
- No penalty occurs if s == t.

The perfect alignment is an alignment which has the least amount of penalty among all other possible alignments.

### example:
- S = GC
- T = CA  
- p_miss = 7
- p_gap = 3
### asnwer:
- S = CG-
- T = C-A
- penalty = 0 + 3 + 3 = 6
