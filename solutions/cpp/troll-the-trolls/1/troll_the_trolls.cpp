namespace hellmath {

enum AccountStatus {
    troll,
    guest,
    user,
    mod,
};

enum Action {
    read,
    write,
    remove,
};

bool display_post(AccountStatus poster, AccountStatus viewer) {
    if (poster == hellmath::AccountStatus::troll) {
        if (viewer != hellmath::AccountStatus::troll)
            return false;
        else
            return true;
    }
    return true;
}

bool permission_check(Action action, AccountStatus account) {
    switch (action) {
    case read:
        switch (account) {
        case troll:
        case user:
        case mod:
        case guest:
            return true;
        default:
            return false;
        }
    case write:
        switch (account) {
        case troll:
        case user:
        case mod:
            return true;
        case guest:
        default:
            return false;
        }

    case remove:
        switch (account) {
        case mod:
            return true;
        case troll:
        case user:
        case guest:
        default:
            return false;
        }
    default:
        return false;
    }
}

bool valid_player_combination(AccountStatus player1, AccountStatus player2) {

    switch (player1) {
        // guests can't play

    case guest:
        return false;
    case troll:
        if (player2 == AccountStatus::troll)
            return true;
        else
            return false;
    default:
        switch (player2) {
        case guest:
            return false;
        case troll:
            return false;
        default:
            return true;
        }
    }
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

bool has_priority(AccountStatus player1, AccountStatus player2) {

    switch (player1) {
    case mod:
        return true;

    case user:
        switch (player2) {
        case mod:
            return false;
        default:
            return true;
        }
    case guest:
        switch (player2) {
        case troll:
            return true;
        default:
            return false;
        }

    case troll:
        return false;
    default:
        return true;
    }
}

} // namespace hellmath
