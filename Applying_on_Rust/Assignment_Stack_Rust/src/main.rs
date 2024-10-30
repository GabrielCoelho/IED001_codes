use std::io;
fn main() {
    let mut i = 0;
    let shunting_yard_alg = read_line_string("Insert the expression to resolve");
    let mut stack_value: Vec<&str> = shunting_yard_alg
        .split_terminator(&['(', ')', '+', '-', '/', '*'][..])
        .collect();
    loop {
        if i < stack_value.len() {
            break;
        }
        if stack_value[i] == "" {
            stack_value.remove(i);
            i = 0;
        }
        i += 1;
    }

    let mut stack_operator: Vec<&str> = shunting_yard_alg
        .split_terminator(&['1', '2', '3', '4', '5', '6', '7', '8', '9', '0'][..])
        .collect();
    show_stack(&stack_value);
    show_stack(&stack_operator);
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

fn show_stack(s: &Vec<&str>) {
    for i in s {
        println!("Content: {i}");
    }
}

/// Read line -> String
///
/// Read the input and save it's contents into a string.
fn read_line_string(msg: &str) -> String {
    println!("{msg}");
    let mut s: String = String::new();
    io::stdin()
        .read_line(&mut s)
        .expect("Couldn't read any number");
    let s: String = if !s.trim().is_empty() {
        s.trim().to_string()
    } else {
        "".to_string()
    };
    s
}
