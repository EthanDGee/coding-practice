fn extract_number_sections(code: &str) -> Vec<&str> {
    code.split_whitespace().collect()
}

fn sin_is_canadian(sections: &Vec<&str>) -> bool {
    sections.iter().all(|sec| sec.len().is_multiple_of(3)) && sections.len() == 3
}

fn double_digits(code: String) -> String {
    let mut code_string = code.to_string();
    unsafe {
        let code_bytes = code_string.as_bytes_mut();
        for (i, byte) in code_bytes.iter_mut().enumerate() {
            if i % 2 == 0 && byte.is_ascii_digit() {
                print!("{}, {}", i, *byte - b'0');
                let mut num = (*byte - b'0') * 2;
                if num >= 10 {
                    num -= 9;
                }
                *byte = num + b'0';
                println!("->{},{}", *byte - b'0', num)
            }
        }
    }
    code_string
}

fn double_canadian(code: String) -> String {
    let mut code_string = code.to_string();
    unsafe {
        let code_bytes = code_string.as_bytes_mut();
        for (i, byte) in code_bytes.iter_mut().enumerate() {
            if i % 2 == 1 && byte.is_ascii_digit() {
                print!("{}, {}", i, *byte - b'0');
                let mut num = (*byte - b'0') * 2;
                if num >= 10 {
                    num -= 9;
                }
                *byte = num + b'0';
                println!("->{},{}", *byte - b'0', num)
            }
        }
    }
    code_string
}

fn check_single_digit(code: &str) -> bool {
    let removed_white_space = code.replace(" ", "");

    removed_white_space.len() <= 1
}

// fn check_zeroes(code: &str) -> bool {
//     let removed_white_space = code.replace(" ", "");
//
//     let zeros: Vec<char> = removed_white_space
//         .chars()
//         .filter(|&digit| digit == '0')
//         .collect();
//
//     zeros.len() > 1
// }

/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    if check_single_digit(code) {
        return false;
    }

    // if check_zeroes(code) {
    //     return false;
    // }
    //
    let sections = extract_number_sections(code);

    let doubled_digits = match sin_is_canadian(&sections) {
        true => double_canadian(sections.join("")),
        false => double_digits(sections.join("")),
    };

    println!(
        "{}\n{}\n{}",
        code,
        doubled_digits,
        sin_is_canadian(&sections)
    );

    // sum all digits and check to see if divisible by 10
    let sum: u32 = doubled_digits.chars().filter_map(|c| c.to_digit(10)).sum();

    sum.is_multiple_of(10)
}
