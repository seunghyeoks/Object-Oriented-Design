#include "gtest/gtest.h"
#include "car_builder.h"
#include "car_parts_factory.h"
#include "car.h"
#include "door.h"
#include "hyundai_parts_factory.h"
#include "kia_parts_factory.h"
#include "part.h"
#include "roof.h"
#include "wheel.h"



class CarBuildTest : public ::testing::Test {
 public:
  CarBuildTest() {}
 protected:
  void SetUp() override {};
  void TearDown() override {};
  HyundaiPartsFactory* hyundai_fac;
  KiaPartsFactory* kia_fac;
  std::string expected;
  Car* car;
};



TEST_F(CarBuildTest, CarBuildingTest_build1) {
    hyundai_fac = HyundaiPartsFactory::GetInstance();

    CarBuilder carBuilder(hyundai_fac);


    car = carBuilder.CreateDoor()
                         .CreateRoof()
                         .CreateWheel()
                         .SetColor("red")
                         .Build();

    expected = "Car([hyundai] Door, [hyundai] Roof, [hyundai] Wheel, red)";
    EXPECT_EQ(car->GetSpec(), expected);
}



TEST_F(CarBuildTest, CarBuildingTest_build2) {
    hyundai_fac = HyundaiPartsFactory::GetInstance();

    CarBuilder carBuilder(hyundai_fac);


    car = carBuilder.CreateDoor()
                         .SetColor("blue")
                         .Build();

    expected = "Car([hyundai] Door, blue)";
    EXPECT_EQ(car->GetSpec(), expected);


    car = carBuilder.CreateDoor()
                    .CreateRoof()
                    .CreateWheel()
                    .Build();

    expected = "Car([hyundai] Door, [hyundai] Roof, [hyundai] Wheel)";
    EXPECT_EQ(car->GetSpec(), expected);


    car = carBuilder.Build();

    EXPECT_EQ(car->GetSpec(), "Car()");
}



TEST_F(CarBuildTest, CarBuildingTest_assert) {
    kia_fac = KiaPartsFactory::GetInstance();

    CarBuilder carBuilder(kia_fac);

    car = carBuilder.CreateDoor()
                         .CreateRoof()
                         .CreateWheel()
                         .SetColor("gray")
                         .Build();
    expected = "Car([kia] Door, [kia] Roof, [kia] Wheel, gray)";
    EXPECT_EQ(car->GetSpec(), expected);

    carBuilder.CreateDoor();
    ASSERT_DEATH(carBuilder.CreateDoor(), "Duplicated Parts Creation: Door");

    carBuilder.CreateRoof();
    ASSERT_DEATH(carBuilder.CreateRoof(), "Duplicated Parts Creation: Roof");

    carBuilder.CreateWheel();
    ASSERT_DEATH(carBuilder.CreateWheel(), "Duplicated Parts Creation: Wheel");

    carBuilder.SetColor("blue");
    carBuilder.SetColor("green");
    carBuilder.SetColor("aurora");

    car = carBuilder.Build();

    expected = "Car([kia] Door, [kia] Roof, [kia] Wheel, aurora)";
    EXPECT_EQ(car->GetSpec(), expected);
}



TEST_F(CarBuildTest, CarBuildingTest_copy1) {
    kia_fac = KiaPartsFactory::GetInstance();

    CarBuilder carBuilder(kia_fac);

    car = carBuilder.CreateDoor()
                         .CreateRoof()
                         .CreateWheel()
                         .SetColor("gray")
                         .Build();

    Car* new_car = car;

    expected = "Car([kia] Door, [kia] Roof, [kia] Wheel, gray)";
    EXPECT_EQ(new_car->GetSpec(), expected);
}



TEST_F(CarBuildTest, CarBuildingTest_copy2) {
    hyundai_fac = HyundaiPartsFactory::GetInstance();
    kia_fac = KiaPartsFactory::GetInstance();

    CarBuilder carBuilder(hyundai_fac);
    CarBuilder carBuilder2(kia_fac);

    Car* car = carBuilder.CreateDoor()
                         .SetColor("gray")
                         .Build();

    Car* new_car = car;
    Car* new_car2(car);

    expected = "Car([hyundai] Door, gray)";
    EXPECT_EQ(new_car->GetSpec(), expected);
    EXPECT_EQ(new_car2->GetSpec(), expected);


    Car* car2 = carBuilder2.CreateRoof()
                           .SetColor("blue")
                           .Build();

    new_car = car2;
    Car* new_car3(car2);

    expected = "Car([kia] Roof, blue)";
    EXPECT_EQ(new_car->GetSpec(), expected);
    EXPECT_EQ(new_car3->GetSpec(), expected);
}

TEST_F(CarBuildTest, FactoryTest) {
    hyundai_fac = HyundaiPartsFactory::GetInstance();
    kia_fac = KiaPartsFactory::GetInstance();

    Part* d = hyundai_fac->CreateDoor();
    EXPECT_EQ(d->GetInfo(), "[hyundai] Door");

    Part* w = kia_fac->CreateWheel();
    EXPECT_EQ(w->GetInfo(), "[kia] Wheel");

    Part* r = hyundai_fac->CreateRoof();
    EXPECT_EQ(r->GetInfo(), "[hyundai] Roof");
}
