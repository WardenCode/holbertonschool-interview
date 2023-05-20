#!/usr/bin/python3
"""
Write a recursive function that queries the Reddit API, parses
the title of all hot articles, and prints a sortedcount
of given keywords (case-insensitive, delimited by spaces).
"""

from requests import get
import re

header = {
    'User-Agent': 'Linux:api_advanced:v0.0.0 (by /u/ElEnriquez)'
}


def iterate_children(childrens, word_list, count_of_word):
    """
    Go through the childrens of response of Reddit API

    Args:
        childrens (List[dict]): List of reddits obtained from the subreddit
        word_list (List[str]): List of wordts to search on titles
        count_of_word (dict): Dictionary with the
        count of the matching words on the titles
    """

    regex = r'({})'.format('|'.join(word_list))

    for children in childrens:
        title = children.get('data').get('title')
        re_obj = re.search(regex, title, re.IGNORECASE)
        if (re_obj is None):
            continue
        founded = [element.lower() for element in re_obj.groups()]
        for word in founded:
            if (count_of_word.get(word)):
                count_of_word[word] += 1
            else:
                count_of_word[word] = 1


def count_words(subreddit, word_list, after='start', count_of_words={}):
    """
    Count words on the hot topics of one subreddit.
    and count it doing match with the word_list

    Args:
        subreddit (str): Subreddit to search the hot topics.
        word_list (List[str]): Words to search on the subreddit.
        after (str | None): String to go to the next page
        of the response about subreddit.
        count_of_word (dict): Dictionary with the count of words to search.

    Return: None
    """
    reddit_url = 'https://www.reddit.com'
    base_url = '{}/r/{}/hot.json?after={}#'.format(reddit_url, subreddit, after)
    response = get(base_url, headers=header, allow_redirects=False)

    if ((response.status_code != 200) or (after is None)):
        return

    data = response.json().get('data')
    elements = data.get('children')

    if (after == 'start'):
        word_list = set([word.lower() for word in word_list])

    iterate_children(elements, word_list, count_of_words)
    count_words(subreddit, word_list, data.get('after'), count_of_words)

    if (len(count_of_words) != 0 and after == 'start'):
        count_of_words = dict(
            sorted(count_of_words.items(), key=lambda item: item[1]))
        for key, value in count_of_words.items():
            print("{}: {}".format(key, value))
