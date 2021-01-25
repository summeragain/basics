use std::fs::File;
use std::io::prelude::*;
use std::io::{self, BufReader};

fn main() {
    let result_part1: i32 = part1();
    let result_part2: i128 = part2();

    println!("Answer for part 1: {:?}", result_part1);
    println!("Answer for part 2: {:?}", result_part2);
}

fn read_file(file_name: &str) -> io::Result<Vec<i32>> {
    let filename = String::from(file_name);

    let f = File::open(filename)?;
    let f = BufReader::new(f);
    let mut _original: Vec<i32> = Vec::new();

    for line in f.lines() {
        for value in line.unwrap().split(",") {
            _original.push(value.parse().unwrap());
        }
    }

    Ok(_original)
}

fn part1() -> i32 {
    // 1. Read data
    // 2. Loop all numbers to get Y = 2020 - X and search through vec for this number
    // 3. When the number is found, multiply them and return the answer

    let _original = read_file("input.txt").ok().unwrap_or(Vec::new());
    let mut result = 1;

    for number in _original.iter() {
        let possible_third = 2020 as i32 - number;

        if _original.contains(&possible_third) {
            result = number * possible_third;
            return result;
        }
    }

    return result;
}

fn part2() -> i128 {
    let mut _original = read_file("input.txt").ok().unwrap_or(Vec::new());
    let mut result: i128 = 1;

    let mut sum_of_two_vec = _original.clone();
    sum_of_two_vec = sum_of_two_vec
        .into_iter()
        .map(|x| 2020 as i32 - x)
        .collect();

    for i in 0..sum_of_two_vec.len() {
        let sum_of_two = sum_of_two_vec[i];

        for j in 0.._original.len() {
            if i != j {
                let first = 2020 - sum_of_two;
                let second = _original[j];

                for k in 0.._original.len() {
                    let third = 2020 - first - second;

                    if j != k && third > 0 && _original.contains(&third) {
                        println!("Numbers: {0}, {1}, {2}", first, second, third);
                        result = (first * second * third).into();
                        return result;
                    }
                }
            }
        }
    }

    return result;
}
