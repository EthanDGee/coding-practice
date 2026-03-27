fn extract_number_sections(code: &str) -> Vec<&str> {
    code.split_whitespace().collect()
}

fn double_digits(code: String) -> Option<String> {
    let mut code_string = code.to_string();

    unsafe {
        let code_bytes = code_string.as_bytes_mut();
        for (i, byte) in code_bytes.iter_mut().enumerate() {
            // if the value is not an ascii digit the sequence is invalid
            if !byte.is_ascii_digit() {
                return None;
            }

            if i % 2 == 1 {
                print!("{}, {}", i, *byte - b'0');
                let mut num = (*byte - b'0') * 2;
                // if num == 9 * 2 {
                //     // 9 is a special case and is converted to 8
                //     num = 8;
                // } else
                if num >= 10 {
                    num -= 9;
                }
                *byte = num + b'0';
                println!("->{},{}", *byte - b'0', num)
            }
        }
    }
    Some(code_string)
}

fn check_single_digit(code: &str) -> bool {
    let removed_white_space = code.replace(" ", "");

    removed_white_space.len() <= 1
}

/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    if check_single_digit(code) {
        return false;
    }

    // handle sectioning
    let sections = extract_number_sections(code);
    let joined_sections = sections.join("").chars().rev().collect();

    // attempt to double returning false if there is a parsing error
    let doubled_digits = match double_digits(joined_sections) {
        Some(doubled) => doubled,
        None => return false,
    };

    // sum all digits and check to see if divisible by 10
    let sum: u32 = doubled_digits.chars().filter_map(|c| c.to_digit(10)).sum();

    sum.is_multiple_of(10)
}
