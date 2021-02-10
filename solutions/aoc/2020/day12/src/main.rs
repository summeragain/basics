use std::fs::File;
use std::io::prelude::*;
use std::io::BufReader;

fn main() {
    let result_part1 = part1();
    let result_part2 = part2();

    println!("Answer for part 1: {:?}", result_part1);
    println!("Answer for part 2: {:?}", result_part2);
}

fn part1() -> i64 {
    // 1. Read the file
    // 2. Check every direction
    // 3. Sum counters

    let mut current_index = 1;
    let mut east_counter: i64 = 0;
    let mut north_counter: i64 = 0;
    let mut direction = 'E';
    let instructions: Vec<(char, i64)> = read_file("input.txt");

    for instruction in instructions {
        implement_instruction(instruction, &mut east_counter, &mut north_counter, &mut direction, &mut current_index);
    }


    return east_counter.abs() + north_counter.abs();
}

fn implement_instruction(pair: (char, i64), east_counter: &mut i64, north_counter: &mut i64, direction: &mut char, current_index: &mut i64) {
    let cardinal_directions = ['N', 'E', 'S', 'W'];

    match pair.0 {
        'F' => {
            implement_instruction((*direction, pair.1), east_counter, north_counter, direction, current_index);
        },
        'L' => {
            *current_index -= pair.1 / 90;
            if *current_index < 0 {
                 *current_index = cardinal_directions.len() as i64 - current_index.abs();
            } 
            *direction = cardinal_directions[*current_index as usize];
        },
        'R' => {
            *current_index += pair.1 / 90;
            if *current_index >= cardinal_directions.len() as i64 {
                 *current_index -= cardinal_directions.len() as i64;
            } 
            *direction = cardinal_directions[*current_index as usize];
        },
        'N' => {
            *north_counter += pair.1;
        },
        'E' => {
            *east_counter += pair.1;
        },
        'S' => {
            *north_counter -= pair.1;
        },
        'W' => {
            *east_counter -= pair.1;
        },
        _ => {},
    }
}

fn read_file(file_name: &str) -> Vec<(char, i64)> {
    let filename = String::from(file_name);
    let file = File::open(filename).expect("no such file");
    let buf = BufReader::new(file);

    buf.lines()
        .map(|x| x.unwrap())
        .map(|x| {
            (
                x.chars().next().unwrap(),
                x.to_string().split_off(1).parse::<i64>().unwrap(),
            )
        })
        .collect()
}

struct Point {
    north: i64,
    east: i64
}

fn part2() -> i64 {
    let mut ship = Point { north: 0, east: 0 };
    let mut waypoint = Point { north: 1, east: 10 };
    let instructions: Vec<(char, i64)> = read_file("input.txt");

    for instruction in instructions {
        implement_instruction_part2(instruction, &mut ship, &mut waypoint);
    }


    return ship.north.abs() + ship.east.abs();
}

fn rotate(waypoint: &mut Point, sign: i64) {
	let temp = waypoint.east;
	waypoint.east = -1 * sign * waypoint.north;
	waypoint.north = sign * temp;
}

fn implement_instruction_part2(pair: (char, i64), ship: &mut Point, waypoint: &mut Point) {
    match pair.0 {
        'F' => {
            ship.north += waypoint.north * pair.1;
            ship.east += waypoint.east * pair.1;
        },
        'L' => {
            let count = pair.1 / 90;
            for i in 0..count {
                rotate(waypoint, 1);
            }
        },
        'R' => {		
            let count = pair.1 / 90;
            for i in 0..count {
                rotate(waypoint, -1);
            }
        },
        'N' => {
            waypoint.north += pair.1;
        },
        'E' => {
            waypoint.east += pair.1;
        },
        'S' => {
            waypoint.north -= pair.1;
        },
        'W' => {
            waypoint.east -= pair.1;
        },
        _ => {},
    }
}