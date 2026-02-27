pub fn is_leap_year(year: u64) -> bool {
    if year.is_multiple_of(100) {
        return year.is_multiple_of(400);
    }

    year.is_multiple_of(4)
}
