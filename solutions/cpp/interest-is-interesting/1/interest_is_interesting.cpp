// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance) {
    if (balance < 0)
        return 3.213;
    if (balance < 1000)
        return 0.5;
    if (balance < 5000)
        return 1.621;

    // grater than 5000
    return 2.475;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance) {

    double rate = interest_rate(balance) / 100.0;

    return balance * rate;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance) {

    return yearly_interest(balance) + balance;
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance) {
    // TODO: Implement the years_until_desired_balance function
    int years_remaining = 0;

    while (balance < target_balance) {
        balance = annual_balance_update(balance);
        years_remaining++;
    }

    return years_remaining;
}
