#include "tables_stack.h"

TablesStack::TablesStack() {
    symbol_table.push_back(std::vector<Entry>());
}

void TablesStack::push() {
    // Push an empty table onto the stack
    symbol_table.push_back(std::vector<Entry>());
}

std::vector<Entry> TablesStack::pop() {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    std::vector<Entry> top = symbol_table.back();
    symbol_table.pop_back();
    return top;
}

bool TablesStack::empty() const {
    return symbol_table.empty();
}

size_t TablesStack::size() const {
    return symbol_table.size();
}

const std::vector<Entry>& TablesStack::top() const {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return symbol_table.back();
}

void TablesStack::addToTopTable(const Entry& entry) {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    top().push_back(entry); // Add entry to the back of the top table
}

Entry TablesStack::searchEntry(const std::string& name) const {
    // Iterate through tables from top to bottom
    for (const auto& table : symbol_table) {
        auto it = std::find_if(table.begin(), table.end(), [&name](const Entry& entry) { return entry.name == name; });
        if (it != table.end()) {
            return *it; // Return the found Entry
        }
    }
    throw std::runtime_error("Entry not found in the stack");
}
