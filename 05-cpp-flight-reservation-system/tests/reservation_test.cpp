#include <cassert>
#include <sstream>
#define main reservation_app_main
#include "../Waleed_Hotel.cpp"
#undef main

void book(const std::string &input, rese reservations[50], flight flights[5], int &count)
{
    std::istringstream stream(input);
    auto *previous = std::cin.rdbuf(stream.rdbuf());
    std::cin.clear();
    Bookflight(reservations, flights, count);
    std::cin.rdbuf(previous);
    std::cin.clear();
}

int main()
{
    flight flights[5];
    rese reservations[50];
    FlightsInfo(flights);
    int count = 0;
    book("Test Passenger\n1\n2\n", reservations, flights, count);
    assert(count == 1 && flights[0].seatsavailable == 13);
    assert(Calculat(flights, reservations, count) == 3000);
    assert(CalculateTotalSeats(reservations, count) == 2);
    for (const auto &input : {"Test\n1\n-2\n", "Test\n1\n0\n", "Test\n1\n99\n", "Test\n99\n"})
    {
        book(input, reservations, flights, count);
        assert(count == 1 && flights[0].seatsavailable == 13);
    }
    book("Test\ninvalid\n2\ninvalid\n1\n", reservations, flights, count);
    assert(count == 2 && flights[1].seatsavailable == 11);
    assert(Calculat(flights, reservations, count) == 4800);
    assert(CalculateTotalSeats(reservations, count) == 3);
    count = 50;
    book("", reservations, flights, count);
    assert(count == 50 && flights[0].seatsavailable == 13);
    std::cout << "PASS: valid booking, totals, negative/zero seats, overbooking, invalid flight, text input, reservation capacity.\n";
}
