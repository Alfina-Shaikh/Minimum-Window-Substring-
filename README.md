
Minimum Window Substring

A C implementation of the Minimum Window Substring problem. The objective is to find the shortest substring of a video stream that contains all the characters required by an evidence pattern, including duplicate character requirements.

Problem Statement

Given a "video_stream" and an "evidence_pattern", find the shortest contiguous substring of the video stream containing all characters required by the evidence pattern.

If a valid substring is found, return its contents and its start and end indices. Otherwise, report that the incident was not found.

Approach

This solution uses the sliding window technique with two pointers.

- Left pointer: Tracks the beginning of the current window and moves forward to shorten a valid window.
- Right pointer: Moves through the video stream to expand the window.
- Required frequency array: Stores the number of occurrences needed for each character.
- Window frequency array: Tracks the character counts in the current window.

When the window contains all required characters, the solution attempts to shrink it to find the shortest valid substring.

Complexity Analysis

- Time Complexity: O(N + M), where N is the length of the video stream and M is the length of the evidence pattern.
- Auxiliary Space Complexity: O(1), assuming fixed-size character frequency arrays.

Files

- "solution.c" — C implementation of the solution.
- "1_Tech_Interview.pdf" — Original problem statement, shared with permission.

Example

Input

- Video stream: "PABLOFORBADBOY"
- Evidence pattern: "ADB"

Expected result

- Shortest substring: "BAD"
- Start index: "8"
- End index: "10"

Language

C

Learning Goals

- String manipulation in C
- Sliding window technique
- Two-pointer approach
- Character frequency counting
- Finding the shortest valid substring
