/*
Challenge 207

Task 2: H-Index
Submitted by: Mohammad S Anwar

You are given an array of integers containing citations a researcher has
received for each paper.

Write a script to compute the researcher’s H-Index. For more information
please checkout the wikipedia page.

    The H-Index is the largest number h such that h articles have at least h
    citations each. For example, if an author has five publications,
    with 9, 7, 6, 2, and 1 citations (ordered from greatest to least),
    then the author’s h-index is 3, because the author has three publications
    with 3 or more citations. However, the author does not have four
    publications with 4 or more citations.


Example 1

Input: @citations = (10,8,5,4,3)
Output: 4

Because the 4th publication has 4 citations and the 5th has only 3.

Example 2

Input: @citations = (25,8,5,3,3)
Output: 3

The H-Index is 3 because the fourth paper has only 3 citations.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int h_index(std::vector<int>& articles) {
    std::sort(articles.rbegin(), articles.rend());
    for (size_t i = 0; i < articles.size(); i++)
        if (articles[i] < i+1)
            return i+1-1;
    return -1;
}

int main(int argc, char* argv[]) {
    argv++; argc--;
    std::vector<int> articles;
    for (int i = 0; i < argc; i++)
        articles.push_back(atoi(argv[i]));
    std::cout << h_index(articles) << std::endl;
}
