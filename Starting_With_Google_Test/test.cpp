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
};

// Inherit from Test
struct BankAccountTest : testing::Test {

    BankAccount* account;

    // Test constructor
    BankAccountTest() {
        account = new BankAccount;
    }

    // Test destructor
    ~BankAccountTest() {
        delete account;
    }
};

// Goup name, particular test name
TEST_F(BankAccountTest, BankAccountStartsEmpty) {

    // Excpect to be equal
    EXPECT_EQ(0, account->balance);
}

int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}