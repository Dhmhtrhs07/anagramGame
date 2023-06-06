#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>

// Function to check if two words are anagrams of each other
bool isAnagram(const std::string& word1, const std::string& word2) {
    if (word1.length() != word2.length())
        return false;

    std::unordered_map<char, int> charCount;

    for (char c : word1)
        charCount[c]++;

    for (char c : word2) {
        if (charCount[c] == 0)
            return false;
        charCount[c]--;
    }

    return true;
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> wordCategories;
    wordCategories["animals"] = {"dog", "cat", "elephant", "lion", "tiger", "giraffe", "zebra", "monkey", "horse", "sheep", "snake", "turtle", "kangaroo", "dolphin", "penguin", "rabbit", "fox", "bear", "whale", "bat"};
    wordCategories["fruits"] = {"apple", "banana", "orange", "grape", "mango", "strawberry", "watermelon", "pineapple", "kiwi", "peach", "pear", "blueberry", "cherry", "plum", "lemon", "raspberry", "blackberry", "coconut", "avocado", "pomegranate"};
    wordCategories["countries"] = {"usa", "china", "india", "russia", "brazil", "japan", "germany", "france", "italy", "canada", "australia", "mexico", "south africa", "spain", "argentina", "sweden", "netherlands", "belgium", "switzerland", "norway"};
    wordCategories["colors"] = {"red", "blue", "green", "yellow", "orange", "purple", "pink", "black", "white", "gray", "brown", "gold", "silver", "maroon", "navy", "teal", "lime", "olive", "violet", "cyan"};
    wordCategories["sports"] = {"football", "basketball", "tennis", "soccer", "baseball", "volleyball", "golf", "cricket", "rugby", "hockey", "swimming", "athletics", "boxing", "cycling", "skiing", "wrestling", "badminton", "table tennis", "surfing", "karate"};

    int score = 0;
    int mistakes = 0;

    // Game loop
    while (true) {
        // Display categories
        std::cout << "Categories:\n";
        for (const auto& category : wordCategories)
            std::cout << category.first << '\n';

        std::cout << "Enter a category (or 'quit' to exit): ";
        std::string category;
        std::getline(std::cin, category);

        if (category == "quit")
            break;

        // Check if the category exists
        auto categoryIter = wordCategories.find(category);
        if (categoryIter == wordCategories.end()) {
            std::cout << "Invalid category.\n";
            continue;
        }

        
        // Get a random word for the chosen category
        std::vector<std::string>& words = categoryIter->second;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(words.begin(), words.end(), gen);

        std::string word = words[0];

        // Shuffle the word to create an anagram
        std::shuffle(word.begin(), word.end(), gen);

        std::cout << "Anagram: " << word << '\n';

        std::cout << "Enter your answer: ";
        std::string guess;
        std::getline(std::cin, guess);

        if (isAnagram(guess, words[0])) {
            std::cout << "Correct!\n";
            score++;
        } else {
            std::cout << "Wrong answer.\n";
            mistakes++;
        }

        if (mistakes >= 2) {
            std::cout << "Game over! You made too many mistakes.\n";
            break;
        }
    }

    std::cout << "Final score: " << score << '\n';

    return 0;
}
