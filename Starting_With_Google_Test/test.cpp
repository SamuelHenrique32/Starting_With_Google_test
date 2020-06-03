#include "pch.h"
#include<gtest/gtest.h>


/*TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}*/

struct BankAccount {
    int balance = 0;

    BankAccount() {
    }

    explicit BankAccount(const int balance)
        : balance{ balance } {
    }

    void deposit(int amount) {
    
        balance += amount;
    }

    bool withDraw(int amount) {

        if (amount <= balance) {
            balance -= amount;
            return true;
        }

        return false;
    }
};

// Inherit from Test
struct BankAccountTest : testing::Test {

    BankAccount* account;

    // Test constructor
    BankAccountTest() {
        account = new BankAccount;
    }

    // Test destructor
    virtual ~BankAccountTest() {
        delete account;
    }
};

// Goup name, particular test name
TEST_F(BankAccountTest, BankAccountStartsEmpty) {

    // Excpect to be equal
    EXPECT_EQ(0, account->balance);
}

// Deposit test
TEST_F(BankAccountTest, CanDepositMoney) {

    account->deposit(100);

    // Verify if the balance is 100
    EXPECT_EQ(100, account->balance);
}

struct account_state {

    int initial_balance;
    int withdraw_amount;
    int final_balance;
    bool success;

    friend std::ostream& operator<<(std::ostream& os, const account_state& obj) {
        return os
            << "initial_balance: " << obj.initial_balance
            << " withdraw_amount: " << obj.withdraw_amount
            << " final_balance: " << obj.final_balance
            << " success: " << obj.success;
    }
};

struct WithDrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state> {

    WithDrawAccountTest() {
        account->balance = GetParam().initial_balance;
    }
};

TEST_P(WithDrawAccountTest, FinalBalance) {
    
    auto as = GetParam();

    auto success = account->withDraw(as.withdraw_amount);

    EXPECT_EQ(as.final_balance, account->balance);

    EXPECT_EQ(as.success, success);
}

// Test cases
INSTANTIATE_TEST_CASE_P(Default, WithDrawAccountTest,
    testing::Values(
        account_state{100,50,50,true},
        account_state{100,200,100,false}
));

int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}