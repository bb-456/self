// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank {

    uint256 private balance = 0;

    // Deposit money
    function deposit(uint256 amount) public {
        require(amount > 0, "Amount must be greater than zero");
        balance += amount;
    }

    // Withdraw money
    function withdraw(uint256 amount) public {
        require(amount > 0, "Amount must be greater than zero");
        require(amount <= balance, "Insufficient balance");

        balance -= amount;
    }

    // Display current balance
    function showBalance() public view returns (uint256) {
        return balance;
    }
}