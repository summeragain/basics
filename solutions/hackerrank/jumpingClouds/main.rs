use std::io;
use std::io::Write;


fn main() {
    print!("Please write number of clouds: ");
    io::stdout().flush().unwrap();

    let mut input_steps = String::new();
    io::stdin().read_line(&mut input_steps).expect("Failed to read from stdin");

    let clouds_amount = input_steps.trim().parse::<usize>().unwrap();



    print!("Please write sequence: ");
    io::stdout().flush().unwrap();

    let mut input_sequence = String::new();
    io::stdin().read_line(&mut input_sequence).expect("Failed to read from stdin");

    let _clouds = input_sequence.trim().split(" ").map(binary_to_bool).map(str::parse).collect::<Result<Vec<bool>, _>>().unwrap();


    let mut i = 0;
    let mut counter = 0;

    while i < clouds_amount - 1 {
        if (i + 2 < clouds_amount) && !_clouds[i + 2] {
            i = i + 2;
        } else {
            i = i + 1;
        }

        counter += 1;
    }

    println!("Answer is {}", counter);
}

fn binary_to_bool(input: &str) -> &str {
    match input {
        "1" => "true",
        "0" => "false",
        _   => "false",
    }
}