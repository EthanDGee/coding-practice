pub fn is_armstrong_number(num: u32) -> bool {
    let digits: String = num.to_string();
    let num_digits: u32 = digits.len() as u32;
    let sum: u32 = digits
        .chars()
        .filter_map(|c| c.to_digit(10))
        .map(|d| d.pow(num_digits))
        .sum();

    num == sum
}
