// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
use std::io;

/// Read line -> String
///
/// Read the input and save it's contents into a string.
pub fn read_line_string(msg: &str) -> String {
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
/// Read line -> integer
///
/// Read the input and save it's contents into an integer of 32bits.
pub fn read_line_int(msg: &str) -> i32 {
    println!("{msg}");
    let mut s: String = String::new();
    io::stdin()
        .read_line(&mut s)
        .expect("Couldn't read any number");
    let s: i32 = if !s.trim().is_empty() {
        s.trim().parse().expect("Couln't resolve")
    } else {
        0
    };
    s
}
