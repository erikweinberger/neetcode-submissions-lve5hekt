struct Node {
    char letter;
    bool endOfWord;
    std::array<std::unique_ptr<Node>, 26> childNodes;

    Node(char letter, bool endOfWord)
        : letter(letter), endOfWord(endOfWord), childNodes{} {}
};


class PrefixTree {
public:
    PrefixTree() {
    }
    
    void insert(string word) {
        insert_recursive(word, 0, &rootNode);
    }
    
    bool search(string word) {
        return searchRecursive(word, 0, &rootNode);
    }
    
    bool startsWith(string prefix) {
        return startsWith(prefix, 0, &rootNode);
    }

private:
    Node rootNode{' ', false};

    void insert_recursive(string word, int index, Node* node) {
        if (index == word.size()) return;

        int letterIndex = word[index] - 'a';
        bool endOfWord = index == word.size() - 1;
        if (!node->childNodes[letterIndex]) {
            node->childNodes[letterIndex] = std::make_unique<Node>(word[index], endOfWord);
        } else if (endOfWord) {
            node->childNodes[letterIndex]->endOfWord = true;
        }
        insert_recursive(word, index + 1, node->childNodes[letterIndex].get());
    }

    bool searchRecursive(string word, int index, Node* node) {
        if (index == word.size()) return false;

        int letterIndex = word[index] - 'a';
        bool endOfWord = index == word.size() - 1;
        if (!node->childNodes[letterIndex]) {
            return false;
        } else if (node->childNodes[letterIndex]->endOfWord && endOfWord) {
            return true;
        }

        return searchRecursive(word, index + 1, node->childNodes[letterIndex].get());
    }

    bool startsWith(string word, int index, Node* node) {
        if (index == word.size()) return true;

        int letterIndex = word[index] - 'a';
        bool endOfWord = index == word.size() - 1;
        if (!node->childNodes[letterIndex]) {
            return false;
        } else if (endOfWord) {
            return true;
        }

        return startsWith(word, index + 1, node->childNodes[letterIndex].get());
    }

};
