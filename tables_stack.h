#ifndef TABLES_STACK_H
#define TABLES_STACK_H

#include <vector>
#include <stack>
#include <algorithm> // for std::find_if

struct Entry {
    std::string name;
    std::string type;
    bool isConst;
    int offset;
};

class TablesStack {
private:
    std::vector<std::vector<Entry>> symbol_table;

public:
    // Constructor that creates an empty symbol table with one empty table
    TablesStack();

    // Push a new empty table onto the stack
    void push();

    // Pop table from the top of the stack
    std::vector<Entry> pop();

    // Check if the stack is empty
    bool empty() const;

    // Get the size of the stack (number of tables stored)
    size_t size() const;

    // Access the top table (without modifying the stack)
    const std::vector<Entry>& top() const;

    // Add Entry to the table in the top of the stack.
    void addToTopTable(const Entry& entry);

    // Search for an entry with a specific name across all tables (top to bottom)
    // Returns the Entry if found, otherwise throws std::runtime_error
    Entry searchEntry(const std::string& name) const;

};
