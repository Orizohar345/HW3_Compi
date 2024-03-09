#include "tables_stack.h"

TablesStack::TablesStack() {
    symbol_table.push_back(std::vector<Entry>());
    offsets_stack.push_back(0);
    TablesStack::addToTopTable(Entry("print", output::makeFunctionType("STRING", "VOID"), 0), true);
    TablesStack::addToTopTable(Entry("printi", output::makeFunctionType("INT", "VOID"), 0), true);
    TablesStack::addToTopTable(Entry("readi", output::makeFunctionType("INT", "INT"), 0), true);
}

void TablesStack::addNewTable() {
    // Push an empty table onto the stack
    std::cout << "Add New Table" << std::endl;
    symbol_table.push_back(std::vector<Entry>());
}


bool TablesStack::empty() const {
    return symbol_table.empty();
}

size_t TablesStack::size() const {
    return symbol_table.size();
}

std::vector<Entry>& TablesStack::getTopTable() {
    if (TablesStack::empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return symbol_table.back();
}
void TablesStack::removeTopTable() {
    if (empty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    std::vector<Entry>& topTable = TablesStack::getTopTable();
    if (!topTable.empty())
        for (const auto& entry : topTable) {
            if (entry.name == "WHILE")
                continue;

            output::printID(entry.name, entry.offset, entry.type);
            if (!offsets_stack.empty())
                offsets_stack.pop_back();
        }
    symbol_table.pop_back();

}
void TablesStack::addToTopTable(Entry&& entry, bool is_func) {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
     std::cout << "Add New To Top Table" << std::endl;
    if (!is_func) {
         std::cout << "Seg Here13" << std::endl;
        entry.offset = offsets_stack.back();
        offsets_stack.push_back(offsets_stack.back()+1);
    }
    std::cout << "Seg Here1" << std::endl;
    TablesStack::getTopTable().push_back(entry); // Add entry to the back of the top table
    std::cout << "Seg Here12" << std::endl;
}



bool TablesStack::entryExists(const std::string& name) const {
    // Iterate through tables from top to bottom
    std::cout << " ERR " << std::endl;
    for (const auto& table : symbol_table) {
        auto it = std::find_if(table.begin(), table.end(), [&name](const Entry& entry) { return entry.name == name; });
        if (it != table.end()) {
            return true; // Return true if the entry is found
        }
    }
    return false; // Return false if the entry is not found
}

Entry *TablesStack::getEntry(const std::string& name) const {
    // Iterate through tables from top to bottom
    for (const auto& table : symbol_table) {
        auto it = std::find_if(table.begin(), table.end(), [&name](const Entry& entry) { return entry.name == name; });
        if (it != table.end()) {
            return &(*it); // Return the found Entry
        }
    }
    throw std::runtime_error("Entry not found in the stack");
}


