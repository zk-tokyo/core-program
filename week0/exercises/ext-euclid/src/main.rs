use ext_euclid::ext_euclid;
use std::env;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 3 {
        eprintln!("Usage: {} <a> <b>", args[0]);
        process::exit(1);
    }
    let a = args[1].parse::<i32>().unwrap_or_else(|_| {
        eprintln!("Invalid value for a: {}", args[1]);
        process::exit(1);
    });
    let b = args[2].parse::<i32>().unwrap_or_else(|_| {
        eprintln!("Invalid value for b: {}", args[2]);
        process::exit(1);
    });
    let res = ext_euclid(a, b);
    println!("{:?}", res);
}
