mod stack;

use std::io::*;

use stack::*;

pub enum Menu {
    OptDesselect = 0,
    OptAdd = 1,
    OptRemove = 2,
    OptShow = 3,
    OptExit = 4,
}

fn main() {
    println!("Learning Stacks in Rust");
    let mut my_stack = Stack::new();
    let mut removed_from_stack: u8 = 0;
    let mut input = String::new();
    let mut op: Menu = Menu::OptDesselect;
    loop {
        if op == Menu::OptExit {
            break;
        }
        op = menu();
        match op {
            Menu::OptDesselect => op = Menu::OptDesselect,
            Menu::OptAdd => {
                println!("Insert a number:");
                io::stdin().read_line(&mut input).expect("Couldn't read");
                removed_from_stack = match input.trim().parse() {
                    Ok(num) => num,
                    Err(_) => continue,
                };
                my_stack.push(removed_from_stack);
            }
            Menu::OptRemove => {
                removed_from_stack = match my_stack.pop() {
                    None => continue,
                    Some(num) => num,
                }
            }
            Menu::OptShow => println!("{}", my_stack.peek()),
            Menu::OptExit => break,
            _ => op = Menu::OptDesselect,
        }
    }
}

fn menu() -> Menu {
    let mut opt = String::new();
    println!("\nChoose an Option");
    println!("{} - Add in Stack", Menu::OptAdd as u8);
    println!("{} - Remove from Stack", Menu::OptRemove as u8);
    println!("{} - Show Stack", Menu::OptShow as u8);
    println!("{} - Exit", Menu::OptExit as u8);
    io::stdin().read_line(&mut opt).expect("Couldn't read");
    let opt: u8 = match opt.trim().parse() {
        Ok(num) => num,
        Err(_) => 0,
    };
    match opt {
        1 => Menu::OptAdd,
        2 => Menu::OptRemove,
        3 => Menu::OptShow,
        4 => Menu::OptExit,
        _ => Menu::OptDesselect,
    }
}
