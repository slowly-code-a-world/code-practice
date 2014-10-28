/*
Windows search charm | 2 point(s)

The Windows search charm has to provide quick responses to users’ searches for words in their documents. In order to do this it matches the text entered in the search box to every text token on the machine. If the entered text completely matches a token on the machine or even just a the prefix of a token on the machine, it is returned as a result.

Users will input text that they are expecting to find in the document they are searching for. Your job is to find that text and return it back to them. Write a program that is able to provide the user with basic information about whether or not their search term appears in a document and how many times it appears.
Technical details

A token is a complete word with a space or punctuation at either end. The full specification for breaking text into tokens can be found here.
Input Text 	Tokens
This “isn’t” an e-mail. 	

This

isn

t

an

e

mail
User search inputs will be a single text token that doesn’t contain punctuation or spaces.
Matching is not case sensitive (Users don’t know the difference between John and john).

Input description/format

The input will be a single token, followed by a newline. After that, the document that you are to search will start.
Output description/format

Your output should take the format: AnswerToA;AnswerToB;AnswerToC, where a-c are defined below.

Find the number of times the complete token appears in that document.
Find the total number of tokens that have the token from part A as a prefix.
The complete token from the first match found for part B.

Example input

myth

Greek mythology is the body of myths and teachings that belong to the ancient Greeks, concerning their gods and heroes, the nature of the world, and the origins and significance of their own cult and ritual practices. It was a part of the religion in ancient Greece. Modern scholars refer to and study the myths in an attempt to throw light on the religious and political institutions of Ancient Greece and its civilization, and to gain understanding of the nature of myth itself.

Example output

1;4;mythology
*/
