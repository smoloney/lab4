File: README.txt
Author: Sean Moloney
Assignment: Lab 4 Part C
------------------------

For this lab all the functions except remove, iterValuesatLevel and differenceOf work.  Difference will compare tree a and tree b put the differences into tree c, but it will not compare tree b to a.
iterValuesatLevel will return a blank line except for the root level.  Remove simply does not work.  It will return a true value to main that the node was succesfully deleted, but it will seg fault if
you try to call inorderDump on the tree.
