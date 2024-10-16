mod reading_from;
use reading_from::{read_line_int, read_line_string};

#[derive(PartialEq)]
enum Menu {
    OptDesselect = 0,
    OptAdd = 1,
    OptRemove = 2,
    OptShow = 3,
    OptExit = 4,
}

fn main() {
    let mut option: Menu = Menu::OptDesselect;
    let mut stack: Vec<String> = Vec::new();
    while option != Menu::OptExit {
        option = menu();
        match option {
            Menu::OptAdd => add_item_to_stack(&mut stack),
            Menu::OptRemove => println!("Removed: {}", remove_item_from_stack(&mut stack)),
            Menu::OptShow => show_stack(&stack),
            Menu::OptExit => break,
            _ => {
                println!("Option not valid!\nPlease, try again");
            }
        }
    }
}

fn menu() -> Menu {
    println!("{:-15}Menu{:-15}", "", "");
    println!(
        "{} - Add a value\t\t{} - Remove a value\n{} - Show all values\t{} - Exit the program",
        Menu::OptAdd as u32,
        Menu::OptRemove as u32,
        Menu::OptShow as u32,
        Menu::OptExit as u32
    );
    let op = read_line_int("Choose an number: ");
    match op {
        1 => Menu::OptAdd,
        2 => Menu::OptRemove,
        3 => Menu::OptShow,
        4 => Menu::OptExit,
        _ => Menu::OptDesselect,
    }
}

fn add_item_to_stack(s: &mut Vec<String>) {
    let item: String = read_line_string("Let's add something to the stack: ");
    s.push(item);
}

fn remove_item_from_stack(s: &mut Vec<String>) -> String {
    if !s.is_empty() {
        s.pop().expect("String")
    } else {
        "Couldn't remove due to Stack is empty".to_string()
    }
}

fn show_stack(s: &Vec<String>) {
    for i in s {
        println!("Content: {i}");
    }
}
