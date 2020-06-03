#include "pch.h"
#include<gtest/gtest.h>


/*TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}*/

struct BankAccount {
    int balance;

    BankAccount() {
    }

    explicit BankAccount(const int balance)
        : balance{ balance } {
    }
};

// Goup name, particular test name
TEST(AccountTest, BankAccountStartEmpty) {
    
    BankAccount account;

    // Excpect to be equal
    EXPECT_EQ(0, account.balance);
}

int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}