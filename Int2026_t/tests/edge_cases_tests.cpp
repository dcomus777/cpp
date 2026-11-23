#include <gtest/gtest.h>
#include "lib/number.h"

TEST(IntegerLimits, MaxValue) {
    int2026_t max_int = from_int(2147483647);
    EXPECT_TRUE(max_int == from_int(2147483647));
}

TEST(IntegerLimits, MinValue) {
    int2026_t min_int = from_int(-2147483648);
    EXPECT_TRUE(min_int == from_int(-2147483648));
}

TEST(IntegerLimits, ArithmeticWithMAX) {
    int2026_t max_int = from_int(2147483647);
    int2026_t zero = from_int(0);
    int2026_t result = max_int + zero;
    EXPECT_TRUE(result == max_int);
}

TEST(IntegerLimits, ArithmeticWithMIN) {
    int2026_t min_int = from_int(-2147483648);
    int2026_t zero = from_int(0);
    int2026_t result = min_int + zero;
    EXPECT_TRUE(result == min_int);
}

TEST(PowersOfTwo, Power8) {
    int2026_t power_8 = from_int(256);
    int2026_t expected_8 = from_string("256");
    EXPECT_TRUE(power_8 == expected_8);
}

TEST(PowersOfTwo, Power16) {
    int2026_t power_16 = from_string("65536");
    int2026_t expected_16 = from_string("65536");
    EXPECT_TRUE(power_16 == expected_16);
}

TEST(PowersOfTwo, Power32) {
    int2026_t power_32 = from_string("4294967296");
    int2026_t expected_32 = from_string("4294967296");
    EXPECT_TRUE(power_32 == expected_32);
}

TEST(PowersOfTen, Power10) {
    int2026_t power_10 = from_string("10000000000");
    int2026_t expected_10 = from_string("10000000000");
    EXPECT_TRUE(power_10 == expected_10);
}

TEST(PowersOfTen, Power20) {
    int2026_t power_20 = from_string("100000000000000000000");
    int2026_t expected_20 = from_string("100000000000000000000");
    EXPECT_TRUE(power_20 == expected_20);
}

TEST(PowersOfTen, Power50) {
    int2026_t power_50 = from_string("100000000000000000000000000000000000000000000000000");
    int2026_t expected_50 = from_string("100000000000000000000000000000000000000000000000000");
    EXPECT_TRUE(power_50 == expected_50);
}

TEST(SingleDigit, Zero) {
    int2026_t num = from_int(0);
    int2026_t expected = from_int(0);
    EXPECT_TRUE(num == expected);
}

TEST(SingleDigit, One) {
    int2026_t num = from_int(1);
    int2026_t expected = from_int(1);
    EXPECT_TRUE(num == expected);
}

TEST(SingleDigit, Five) {
    int2026_t num = from_int(5);
    int2026_t expected = from_int(5);
    EXPECT_TRUE(num == expected);
}

TEST(SingleDigit, Nine) {
    int2026_t num = from_int(9);
    int2026_t expected = from_int(9);
    EXPECT_TRUE(num == expected);
}

TEST(AlternatingSign, AdditionOpposites) {
    int2026_t a = from_int(100);
    int2026_t b = from_int(-100);
    int2026_t sum = a + b;
    int2026_t zero = from_int(0);
    EXPECT_TRUE(sum == zero);
}

TEST(AlternatingSign, MultiplicationOpposites) {
    int2026_t a = from_int(100);
    int2026_t b = from_int(-100);
    int2026_t product = a * b;
    int2026_t expected_negative = from_int(-10000);
    EXPECT_TRUE(product == expected_negative);
}

TEST(RepeatedOperations, PowerOf2Through10Multiplications) {
    int2026_t result = from_int(1);
    int2026_t two = from_int(2);

    for(int i = 0; i < 10; ++i) {
        result = result * two;
    }

    int2026_t expected = from_int(1024);
    EXPECT_TRUE(result == expected);
}

TEST(ZeroOperations, DivisionZeroByNumber) {
    int2026_t zero = from_int(0);
    int2026_t any_num = from_int(12345);
    int2026_t div_result = zero / any_num;
    EXPECT_TRUE(div_result == zero);
}

TEST(ZeroOperations, MultiplicationZeroByNumber) {
    int2026_t zero = from_int(0);
    int2026_t any_num = from_int(12345);
    int2026_t mult_result = zero * any_num;
    EXPECT_TRUE(mult_result == zero);
}

TEST(StringSpecialCases, AllOnesPattern) {
    int2026_t all_ones = from_string("11111111111111111111");
    int2026_t expected_ones = from_string("11111111111111111111");
    EXPECT_TRUE(all_ones == expected_ones);
}

TEST(StringSpecialCases, AlternatingPattern) {
    int2026_t alternating = from_string("12121212121212121212");
    int2026_t expected_alt = from_string("12121212121212121212");
    EXPECT_TRUE(alternating == expected_alt);
}

namespace {
// Exact decimal constants computed with arbitrary-precision integers.
constexpr char kMin[] =
    "-38524873341692694784062953816258850050501945817131381073153430733114069865784515015121938480762"
    "140111552140666153309368484162758768190051430568876727161744976795765599371190180480715930926385"
    "053153106735210499248834600709250712104036615007327170575226046616854710942557916135658670742283"
    "591690539269364339735405842530332019830566614611821853512354106945188429424855477403796942463765"
    "693085372756234245511432559422974250867196747777880611779267673973676697293862380060107332123303"
    "663402983071478523401581857851243801948946769234261933563516396910150515362424306395215312516218"
    "00103006196612375759310228062994432";
constexpr char kMax[] =
    "385248733416926947840629538162588500505019458171313810731534307331140698657845150151219384807621"
    "401115521406661533093684841627587681900514305688767271617449767957655993711901804807159309263850"
    "531531067352104992488346007092507121040366150073271705752260466168547109425579161356586707422835"
    "916905392693643397354058425303320198305666146118218535123541069451884294248554774037969424637656"
    "930853727562342455114325594229742508671967477778806117792676739736766972938623800601073321233036"
    "634029830714785234015818578512438019489467692342619335635163969101505153624243063952153125162180"
    "0103006196612375759310228062994431";
constexpr char kHalfRange[] =
    "192624366708463473920314769081294250252509729085656905365767153665570349328922575075609692403810"
    "700557760703330766546842420813793840950257152844383635808724883978827996855950902403579654631925"
    "265765533676052496244173003546253560520183075036635852876130233084273554712789580678293353711417"
    "958452696346821698677029212651660099152833073059109267561770534725942147124277387018984712318828"
    "465426863781171227557162797114871254335983738889403058896338369868383486469311900300536660616518"
    "317014915357392617007909289256219009744733846171309667817581984550752576812121531976076562581090"
    "0051503098306187879655114031497216";
constexpr char kModulus[] =
    "770497466833853895681259076325177001010038916342627621463068614662281397315690300302438769615242"
    "802231042813323066187369683255175363801028611377534543234899535915311987423803609614318618527701"
    "063062134704209984976692014185014242080732300146543411504520932337094218851158322713173414845671"
    "833810785387286794708116850606640396611332292236437070247082138903768588497109548075938849275313"
    "861707455124684910228651188459485017343934955557612235585353479473533945877247601202146642466073"
    "268059661429570468031637157024876038978935384685238671270327938203010307248486127904306250324360"
    "0206012393224751518620456125988864";
constexpr char kAboveMax[] =
    "385248733416926947840629538162588500505019458171313810731534307331140698657845150151219384807621"
    "401115521406661533093684841627587681900514305688767271617449767957655993711901804807159309263850"
    "531531067352104992488346007092507121040366150073271705752260466168547109425579161356586707422835"
    "916905392693643397354058425303320198305666146118218535123541069451884294248554774037969424637656"
    "930853727562342455114325594229742508671967477778806117792676739736766972938623800601073321233036"
    "634029830714785234015818578512438019489467692342619335635163969101505153624243063952153125162180"
    "0103006196612375759310228062994432";
constexpr char kBelowMin[] =
    "-38524873341692694784062953816258850050501945817131381073153430733114069865784515015121938480762"
    "140111552140666153309368484162758768190051430568876727161744976795765599371190180480715930926385"
    "053153106735210499248834600709250712104036615007327170575226046616854710942557916135658670742283"
    "591690539269364339735405842530332019830566614611821853512354106945188429424855477403796942463765"
    "693085372756234245511432559422974250867196747777880611779267673973676697293862380060107332123303"
    "663402983071478523401581857851243801948946769234261933563516396910150515362424306395215312516218"
    "00103006196612375759310228062994433";
constexpr char kNegativeModulus[] =
    "-77049746683385389568125907632517700101003891634262762146306861466228139731569030030243876961524"
    "280223104281332306618736968325517536380102861137753454323489953591531198742380360961431861852770"
    "106306213470420998497669201418501424208073230014654341150452093233709421885115832271317341484567"
    "183381078538728679470811685060664039661133229223643707024708213890376858849710954807593884927531"
    "386170745512468491022865118845948501734393495555761223558535347947353394587724760120214664246607"
    "326805966142957046803163715702487603897893538468523867127032793820301030724848612790430625032436"
    "00206012393224751518620456125988864";
}  // namespace

TEST(Int2026Limits, StorageSize) {
    EXPECT_LE(sizeof(int2026_t), 254u);
}

TEST(Int2026Limits, FullWidthAndSignBit) {
    int2026_t power = from_int(1);
    for (int bit = 0; bit < 2024; ++bit) {
        power = power + power;
    }
    EXPECT_TRUE(power == from_string(kHalfRange));
    EXPECT_TRUE(power != from_int(0));
    EXPECT_TRUE(power != from_int(0) - power);
    const int2026_t minimum = power + power;
    EXPECT_TRUE(minimum == from_string(kMin));
    EXPECT_TRUE(minimum != from_int(0));
    EXPECT_TRUE((minimum + minimum) == from_int(0));
    EXPECT_TRUE((power + (power - from_int(1))) == from_string(kMax));
}

TEST(Int2026Limits, DistinctBoundaries) {
    const int2026_t minimum = from_string(kMin);
    const int2026_t maximum = from_string(kMax);
    EXPECT_FALSE(minimum == maximum);
    EXPECT_TRUE(minimum != maximum);
    EXPECT_TRUE(maximum != from_int(-1));
    EXPECT_TRUE(minimum != from_int(0));
}

TEST(Int2026Limits, AdditionWrapsAt2026Bits) {
    EXPECT_TRUE((from_string(kMax) + from_int(1)) == from_string(kMin));
    EXPECT_TRUE((from_string(kMax) + from_string(kMax)) == from_int(-2));
}

TEST(Int2026Limits, SubtractionWrapsAt2026Bits) {
    EXPECT_TRUE((from_string(kMin) - from_int(1)) == from_string(kMax));
    EXPECT_TRUE((from_string(kMax) - from_string(kMin)) == from_int(-1));
    EXPECT_TRUE((from_int(0) - from_string(kMin)) == from_string(kMin));
}

TEST(Int2026Limits, MultiplicationWrapsAt2026Bits) {
    EXPECT_TRUE((from_string(kMin) * from_int(2)) == from_int(0));
    EXPECT_TRUE((from_string(kMax) * from_int(2)) == from_int(-2));
    EXPECT_TRUE((from_string(kMax) * from_string(kMax)) == from_int(1));
    EXPECT_TRUE((from_string(kMin) * from_int(-1)) == from_string(kMin));
}

TEST(Int2026Limits, DivisionAtBoundaries) {
    const int2026_t minimum = from_string(kMin);
    const int2026_t maximum = from_string(kMax);
    EXPECT_TRUE((minimum / from_int(-1)) == minimum);
    EXPECT_TRUE((minimum / from_int(1)) == minimum);
    EXPECT_TRUE((minimum / minimum) == from_int(1));
    EXPECT_TRUE((maximum / maximum) == from_int(1));
    EXPECT_TRUE((maximum / minimum) == from_int(0));
    EXPECT_TRUE((minimum / maximum) == from_int(-1));
    EXPECT_TRUE((minimum / from_int(2)) == (from_int(0) - from_string(kHalfRange)));
    EXPECT_TRUE((maximum / from_int(2)) == (from_string(kHalfRange) - from_int(1)));
}

TEST(Int2026Limits, DecimalConversionWraps) {
    EXPECT_TRUE(from_string(kAboveMax) == from_string(kMin));
    EXPECT_TRUE(from_string(kBelowMin) == from_string(kMax));
    EXPECT_TRUE(from_string(kModulus) == from_int(0));
    EXPECT_TRUE(from_string(kNegativeModulus) == from_int(0));
}

TEST(Division, TruncationTowardZeroForEverySign) {
    EXPECT_TRUE((from_int(7) / from_int(3)) == from_int(2));
    EXPECT_TRUE((from_int(-7) / from_int(3)) == from_int(-2));
    EXPECT_TRUE((from_int(7) / from_int(-3)) == from_int(-2));
    EXPECT_TRUE((from_int(-7) / from_int(-3)) == from_int(2));
    EXPECT_TRUE((from_int(-2) / from_int(3)) == from_int(0));
    EXPECT_TRUE((from_int(2) / from_int(-3)) == from_int(0));
}
