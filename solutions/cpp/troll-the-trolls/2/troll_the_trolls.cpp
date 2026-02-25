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
    if (poster == AccountStatus::troll) {
        if (viewer != AccountStatus::troll)
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

bool has_priority(AccountStatus player1, AccountStatus player2) {

    switch (player1) {
    case mod:
        return player2 != AccountStatus::mod;

    case user:
        switch (player2) {
        case mod:
        case user:
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
        return false;
    }
}

} // namespace hellmath
