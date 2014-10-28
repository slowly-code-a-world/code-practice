/*
Palindrome phrases | 1 point(s)

A Palindrome phrase is a string starting at the beginning of a word and ending at the end of a word that contains the same alphanumeric characters both from left to right and right to left. Given lines of text, find the largest palindrome phrase in each line.
Clarifications

An alphanumeric character is a character that is a number or a letter (punctuation and white space do not count).
For comparing letters, case should be ignored (for example, “Race Car” would be considered a palindrome phrase).
The beginning of a word is an alphanumeric character that is:
preceded by a non-alphanumeric character, or
is the first character in the line.
The end of a word is an alphanumeric character that is:
followed by a non-alphanumeric character, or
is the last character in the line.
The length of the palindrome phrase is measured by the count of the alphanumeric characters it contains (the ignored punctuation, whitespace, etc. do not count toward its length).

Input description/format

Multiple lines of text, each potentially containing a palindrome phrase.
Output description/format

One line for each line of input. Each line should be the substring that is the longest palindrome phrase found in the source line (this should be in the original casing and include any ignored characters). If no palindrome phrase is found, leave a blank line.
Example input

Dee saw a seed.
Unicode has some weird stuff in it. Do not, bob to ☃ nod.

Example output

Dee saw a seed
Do not, bob to ☃ nod


*/
