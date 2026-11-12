
#!/bin/bash

file="addressbook.txt"

createAddressBook() {
    if [ -e "$file" ]; then
        echo "Address book already exists"
    else
        touch "$file"
        echo "Address book created successfully"
    fi
}

viewAddressBook() {
    if [ ! -s "$file" ]; then
        echo "File is empty"
    else
        cat "$file"
    fi
}

insertRecord() {
    echo "Enter record (name,surname,email,mobile no):"
    read record
    echo "$record" >> "$file"
    echo "Record inserted successfully"
}

deleteRecord() {
    echo "Enter the name to delete:"
    read name
    grep -n "$name" "$file"

    echo "Enter the line number to delete:"
    read line
    sed -i "${line}d" "$file"

    echo "Record deleted successfully"
}

modifyRecord() {
    echo "Enter the name to modify:"
    read name
    grep -n "$name" "$file"

    echo "Enter the line number:"
    read line

    echo "Enter new record (name,surname,email,mobile no):"
    read new
    sed -i "${line}c\\$new" "$file"

    echo "Record modified successfully"
}

exitProgram() {
    echo "Exiting program..."
    exit
}

while true
do
    echo "--------------------Address Book--------------------"
    echo "1. Create address book"
    echo "2. View address book"
    echo "3. Insert record"
    echo "4. Delete record"
    echo "5. Modify record"
    echo "6. Exit"
    echo "Enter your choice:"
    read ch

    case $ch in
        1) createAddressBook ;;
        2) viewAddressBook ;;
        3) insertRecord ;;
        4) deleteRecord ;;
        5) modifyRecord ;;
        6) exitProgram ;;
        *) echo "Invalid choice" ;;
    esac
done
