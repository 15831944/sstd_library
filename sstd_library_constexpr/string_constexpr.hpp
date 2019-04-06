#pragma once
 

#include <string_view>
#include "constexpr_string.hpp"

namespace sstd{ 

template<auto ... Args>
class constexpr_string_literal {
    const constexpr static char thisData[]{ Args ... , char(0) };
public:
    inline static constexpr std::string_view toStringView() noexcept {
        return{ thisData , sizeof...(Args) };
    }
    inline static constexpr constexpr_string toConstexprStringView() noexcept{
        return {thisData};
    }
    inline constexpr static const char * data() noexcept {
        return thisData;
    }
    inline constexpr static std::size_t size() noexcept {
        return sizeof...(Args);
    }
};



namespace _detail_sstd_string {

template<std::size_t N,auto ...>
class string_constexpr_builder_helper {
public:
    static_assert(N>0);
    static_assert(N<=512);
};

template< auto ... Args>
class string_constexpr_builder_helper<0,  Args... > {
public:
    using type = constexpr_string_literal< >;
};

template< auto A0 , auto ... Args>
class string_constexpr_builder_helper<1 ,A0,Args ... > {
public:
    using type = constexpr_string_literal< A0 >;
};
#include "string_constexpr.00000001.hpp"
#include "string_constexpr.00000002.hpp"
#include "string_constexpr.00000003.hpp"
#include "string_constexpr.00000004.hpp"
#include "string_constexpr.00000005.hpp"
#include "string_constexpr.00000006.hpp"
#include "string_constexpr.00000007.hpp"
#include "string_constexpr.00000008.hpp"
#include "string_constexpr.00000009.hpp"
#include "string_constexpr.00000010.hpp"
#include "string_constexpr.00000011.hpp"
#include "string_constexpr.00000012.hpp"
#include "string_constexpr.00000013.hpp"
#include "string_constexpr.00000014.hpp"
#include "string_constexpr.00000015.hpp"
#include "string_constexpr.00000016.hpp"
#include "string_constexpr.00000017.hpp"
#include "string_constexpr.00000018.hpp"
#include "string_constexpr.00000019.hpp"
#include "string_constexpr.00000020.hpp"
#include "string_constexpr.00000021.hpp"
#include "string_constexpr.00000022.hpp"
#include "string_constexpr.00000023.hpp"
#include "string_constexpr.00000024.hpp"
#include "string_constexpr.00000025.hpp"
#include "string_constexpr.00000026.hpp"
#include "string_constexpr.00000027.hpp"
#include "string_constexpr.00000028.hpp"
#include "string_constexpr.00000029.hpp"
#include "string_constexpr.00000030.hpp"
#include "string_constexpr.00000031.hpp"
#include "string_constexpr.00000032.hpp"
#include "string_constexpr.00000033.hpp"
#include "string_constexpr.00000034.hpp"
#include "string_constexpr.00000035.hpp"
#include "string_constexpr.00000036.hpp"
#include "string_constexpr.00000037.hpp"
#include "string_constexpr.00000038.hpp"
#include "string_constexpr.00000039.hpp"
#include "string_constexpr.00000040.hpp"
#include "string_constexpr.00000041.hpp"
#include "string_constexpr.00000042.hpp"
#include "string_constexpr.00000043.hpp"
#include "string_constexpr.00000044.hpp"
#include "string_constexpr.00000045.hpp"
#include "string_constexpr.00000046.hpp"
#include "string_constexpr.00000047.hpp"
#include "string_constexpr.00000048.hpp"
#include "string_constexpr.00000049.hpp"
#include "string_constexpr.00000050.hpp"
#include "string_constexpr.00000051.hpp"
#include "string_constexpr.00000052.hpp"
#include "string_constexpr.00000053.hpp"
#include "string_constexpr.00000054.hpp"
#include "string_constexpr.00000055.hpp"
#include "string_constexpr.00000056.hpp"
#include "string_constexpr.00000057.hpp"
#include "string_constexpr.00000058.hpp"
#include "string_constexpr.00000059.hpp"
#include "string_constexpr.00000060.hpp"
#include "string_constexpr.00000061.hpp"
#include "string_constexpr.00000062.hpp"
#include "string_constexpr.00000063.hpp"
#include "string_constexpr.00000064.hpp"
#include "string_constexpr.00000065.hpp"
#include "string_constexpr.00000066.hpp"
#include "string_constexpr.00000067.hpp"
#include "string_constexpr.00000068.hpp"
#include "string_constexpr.00000069.hpp"
#include "string_constexpr.00000070.hpp"
#include "string_constexpr.00000071.hpp"
#include "string_constexpr.00000072.hpp"
#include "string_constexpr.00000073.hpp"
#include "string_constexpr.00000074.hpp"
#include "string_constexpr.00000075.hpp"
#include "string_constexpr.00000076.hpp"
#include "string_constexpr.00000077.hpp"
#include "string_constexpr.00000078.hpp"
#include "string_constexpr.00000079.hpp"
#include "string_constexpr.00000080.hpp"
#include "string_constexpr.00000081.hpp"
#include "string_constexpr.00000082.hpp"
#include "string_constexpr.00000083.hpp"
#include "string_constexpr.00000084.hpp"
#include "string_constexpr.00000085.hpp"
#include "string_constexpr.00000086.hpp"
#include "string_constexpr.00000087.hpp"
#include "string_constexpr.00000088.hpp"
#include "string_constexpr.00000089.hpp"
#include "string_constexpr.00000090.hpp"
#include "string_constexpr.00000091.hpp"
#include "string_constexpr.00000092.hpp"
#include "string_constexpr.00000093.hpp"
#include "string_constexpr.00000094.hpp"
#include "string_constexpr.00000095.hpp"
#include "string_constexpr.00000096.hpp"
#include "string_constexpr.00000097.hpp"
#include "string_constexpr.00000098.hpp"
#include "string_constexpr.00000099.hpp"
#include "string_constexpr.00000100.hpp"
#include "string_constexpr.00000101.hpp"
#include "string_constexpr.00000102.hpp"
#include "string_constexpr.00000103.hpp"
#include "string_constexpr.00000104.hpp"
#include "string_constexpr.00000105.hpp"
#include "string_constexpr.00000106.hpp"
#include "string_constexpr.00000107.hpp"
#include "string_constexpr.00000108.hpp"
#include "string_constexpr.00000109.hpp"
#include "string_constexpr.00000110.hpp"
#include "string_constexpr.00000111.hpp"
#include "string_constexpr.00000112.hpp"
#include "string_constexpr.00000113.hpp"
#include "string_constexpr.00000114.hpp"
#include "string_constexpr.00000115.hpp"
#include "string_constexpr.00000116.hpp"
#include "string_constexpr.00000117.hpp"
#include "string_constexpr.00000118.hpp"
#include "string_constexpr.00000119.hpp"
#include "string_constexpr.00000120.hpp"
#include "string_constexpr.00000121.hpp"
#include "string_constexpr.00000122.hpp"
#include "string_constexpr.00000123.hpp"
#include "string_constexpr.00000124.hpp"
#include "string_constexpr.00000125.hpp"
#include "string_constexpr.00000126.hpp"
#include "string_constexpr.00000127.hpp"
#include "string_constexpr.00000128.hpp"
#include "string_constexpr.00000129.hpp"
#include "string_constexpr.00000130.hpp"
#include "string_constexpr.00000131.hpp"
#include "string_constexpr.00000132.hpp"
#include "string_constexpr.00000133.hpp"
#include "string_constexpr.00000134.hpp"
#include "string_constexpr.00000135.hpp"
#include "string_constexpr.00000136.hpp"
#include "string_constexpr.00000137.hpp"
#include "string_constexpr.00000138.hpp"
#include "string_constexpr.00000139.hpp"
#include "string_constexpr.00000140.hpp"
#include "string_constexpr.00000141.hpp"
#include "string_constexpr.00000142.hpp"
#include "string_constexpr.00000143.hpp"
#include "string_constexpr.00000144.hpp"
#include "string_constexpr.00000145.hpp"
#include "string_constexpr.00000146.hpp"
#include "string_constexpr.00000147.hpp"
#include "string_constexpr.00000148.hpp"
#include "string_constexpr.00000149.hpp"
#include "string_constexpr.00000150.hpp"
#include "string_constexpr.00000151.hpp"
#include "string_constexpr.00000152.hpp"
#include "string_constexpr.00000153.hpp"
#include "string_constexpr.00000154.hpp"
#include "string_constexpr.00000155.hpp"
#include "string_constexpr.00000156.hpp"
#include "string_constexpr.00000157.hpp"
#include "string_constexpr.00000158.hpp"
#include "string_constexpr.00000159.hpp"
#include "string_constexpr.00000160.hpp"
#include "string_constexpr.00000161.hpp"
#include "string_constexpr.00000162.hpp"
#include "string_constexpr.00000163.hpp"
#include "string_constexpr.00000164.hpp"
#include "string_constexpr.00000165.hpp"
#include "string_constexpr.00000166.hpp"
#include "string_constexpr.00000167.hpp"
#include "string_constexpr.00000168.hpp"
#include "string_constexpr.00000169.hpp"
#include "string_constexpr.00000170.hpp"
#include "string_constexpr.00000171.hpp"
#include "string_constexpr.00000172.hpp"
#include "string_constexpr.00000173.hpp"
#include "string_constexpr.00000174.hpp"
#include "string_constexpr.00000175.hpp"
#include "string_constexpr.00000176.hpp"
#include "string_constexpr.00000177.hpp"
#include "string_constexpr.00000178.hpp"
#include "string_constexpr.00000179.hpp"
#include "string_constexpr.00000180.hpp"
#include "string_constexpr.00000181.hpp"
#include "string_constexpr.00000182.hpp"
#include "string_constexpr.00000183.hpp"
#include "string_constexpr.00000184.hpp"
#include "string_constexpr.00000185.hpp"
#include "string_constexpr.00000186.hpp"
#include "string_constexpr.00000187.hpp"
#include "string_constexpr.00000188.hpp"
#include "string_constexpr.00000189.hpp"
#include "string_constexpr.00000190.hpp"
#include "string_constexpr.00000191.hpp"
#include "string_constexpr.00000192.hpp"
#include "string_constexpr.00000193.hpp"
#include "string_constexpr.00000194.hpp"
#include "string_constexpr.00000195.hpp"
#include "string_constexpr.00000196.hpp"
#include "string_constexpr.00000197.hpp"
#include "string_constexpr.00000198.hpp"
#include "string_constexpr.00000199.hpp"
#include "string_constexpr.00000200.hpp"
#include "string_constexpr.00000201.hpp"
#include "string_constexpr.00000202.hpp"
#include "string_constexpr.00000203.hpp"
#include "string_constexpr.00000204.hpp"
#include "string_constexpr.00000205.hpp"
#include "string_constexpr.00000206.hpp"
#include "string_constexpr.00000207.hpp"
#include "string_constexpr.00000208.hpp"
#include "string_constexpr.00000209.hpp"
#include "string_constexpr.00000210.hpp"
#include "string_constexpr.00000211.hpp"
#include "string_constexpr.00000212.hpp"
#include "string_constexpr.00000213.hpp"
#include "string_constexpr.00000214.hpp"
#include "string_constexpr.00000215.hpp"
#include "string_constexpr.00000216.hpp"
#include "string_constexpr.00000217.hpp"
#include "string_constexpr.00000218.hpp"
#include "string_constexpr.00000219.hpp"
#include "string_constexpr.00000220.hpp"
#include "string_constexpr.00000221.hpp"
#include "string_constexpr.00000222.hpp"
#include "string_constexpr.00000223.hpp"
#include "string_constexpr.00000224.hpp"
#include "string_constexpr.00000225.hpp"
#include "string_constexpr.00000226.hpp"
#include "string_constexpr.00000227.hpp"
#include "string_constexpr.00000228.hpp"
#include "string_constexpr.00000229.hpp"
#include "string_constexpr.00000230.hpp"
#include "string_constexpr.00000231.hpp"
#include "string_constexpr.00000232.hpp"
#include "string_constexpr.00000233.hpp"
#include "string_constexpr.00000234.hpp"
#include "string_constexpr.00000235.hpp"
#include "string_constexpr.00000236.hpp"
#include "string_constexpr.00000237.hpp"
#include "string_constexpr.00000238.hpp"
#include "string_constexpr.00000239.hpp"
#include "string_constexpr.00000240.hpp"
#include "string_constexpr.00000241.hpp"
#include "string_constexpr.00000242.hpp"
#include "string_constexpr.00000243.hpp"
#include "string_constexpr.00000244.hpp"
#include "string_constexpr.00000245.hpp"
#include "string_constexpr.00000246.hpp"
#include "string_constexpr.00000247.hpp"
#include "string_constexpr.00000248.hpp"
#include "string_constexpr.00000249.hpp"
#include "string_constexpr.00000250.hpp"
#include "string_constexpr.00000251.hpp"
#include "string_constexpr.00000252.hpp"
#include "string_constexpr.00000253.hpp"
#include "string_constexpr.00000254.hpp"
#include "string_constexpr.00000255.hpp"
#include "string_constexpr.00000256.hpp"
#include "string_constexpr.00000257.hpp"
#include "string_constexpr.00000258.hpp"
#include "string_constexpr.00000259.hpp"
#include "string_constexpr.00000260.hpp"
#include "string_constexpr.00000261.hpp"
#include "string_constexpr.00000262.hpp"
#include "string_constexpr.00000263.hpp"
#include "string_constexpr.00000264.hpp"
#include "string_constexpr.00000265.hpp"
#include "string_constexpr.00000266.hpp"
#include "string_constexpr.00000267.hpp"
#include "string_constexpr.00000268.hpp"
#include "string_constexpr.00000269.hpp"
#include "string_constexpr.00000270.hpp"
#include "string_constexpr.00000271.hpp"
#include "string_constexpr.00000272.hpp"
#include "string_constexpr.00000273.hpp"
#include "string_constexpr.00000274.hpp"
#include "string_constexpr.00000275.hpp"
#include "string_constexpr.00000276.hpp"
#include "string_constexpr.00000277.hpp"
#include "string_constexpr.00000278.hpp"
#include "string_constexpr.00000279.hpp"
#include "string_constexpr.00000280.hpp"
#include "string_constexpr.00000281.hpp"
#include "string_constexpr.00000282.hpp"
#include "string_constexpr.00000283.hpp"
#include "string_constexpr.00000284.hpp"
#include "string_constexpr.00000285.hpp"
#include "string_constexpr.00000286.hpp"
#include "string_constexpr.00000287.hpp"
#include "string_constexpr.00000288.hpp"
#include "string_constexpr.00000289.hpp"
#include "string_constexpr.00000290.hpp"
#include "string_constexpr.00000291.hpp"
#include "string_constexpr.00000292.hpp"
#include "string_constexpr.00000293.hpp"
#include "string_constexpr.00000294.hpp"
#include "string_constexpr.00000295.hpp"
#include "string_constexpr.00000296.hpp"
#include "string_constexpr.00000297.hpp"
#include "string_constexpr.00000298.hpp"
#include "string_constexpr.00000299.hpp"
#include "string_constexpr.00000300.hpp"
#include "string_constexpr.00000301.hpp"
#include "string_constexpr.00000302.hpp"
#include "string_constexpr.00000303.hpp"
#include "string_constexpr.00000304.hpp"
#include "string_constexpr.00000305.hpp"
#include "string_constexpr.00000306.hpp"
#include "string_constexpr.00000307.hpp"
#include "string_constexpr.00000308.hpp"
#include "string_constexpr.00000309.hpp"
#include "string_constexpr.00000310.hpp"
#include "string_constexpr.00000311.hpp"
#include "string_constexpr.00000312.hpp"
#include "string_constexpr.00000313.hpp"
#include "string_constexpr.00000314.hpp"
#include "string_constexpr.00000315.hpp"
#include "string_constexpr.00000316.hpp"
#include "string_constexpr.00000317.hpp"
#include "string_constexpr.00000318.hpp"
#include "string_constexpr.00000319.hpp"
#include "string_constexpr.00000320.hpp"
#include "string_constexpr.00000321.hpp"
#include "string_constexpr.00000322.hpp"
#include "string_constexpr.00000323.hpp"
#include "string_constexpr.00000324.hpp"
#include "string_constexpr.00000325.hpp"
#include "string_constexpr.00000326.hpp"
#include "string_constexpr.00000327.hpp"
#include "string_constexpr.00000328.hpp"
#include "string_constexpr.00000329.hpp"
#include "string_constexpr.00000330.hpp"
#include "string_constexpr.00000331.hpp"
#include "string_constexpr.00000332.hpp"
#include "string_constexpr.00000333.hpp"
#include "string_constexpr.00000334.hpp"
#include "string_constexpr.00000335.hpp"
#include "string_constexpr.00000336.hpp"
#include "string_constexpr.00000337.hpp"
#include "string_constexpr.00000338.hpp"
#include "string_constexpr.00000339.hpp"
#include "string_constexpr.00000340.hpp"
#include "string_constexpr.00000341.hpp"
#include "string_constexpr.00000342.hpp"
#include "string_constexpr.00000343.hpp"
#include "string_constexpr.00000344.hpp"
#include "string_constexpr.00000345.hpp"
#include "string_constexpr.00000346.hpp"
#include "string_constexpr.00000347.hpp"
#include "string_constexpr.00000348.hpp"
#include "string_constexpr.00000349.hpp"
#include "string_constexpr.00000350.hpp"
#include "string_constexpr.00000351.hpp"
#include "string_constexpr.00000352.hpp"
#include "string_constexpr.00000353.hpp"
#include "string_constexpr.00000354.hpp"
#include "string_constexpr.00000355.hpp"
#include "string_constexpr.00000356.hpp"
#include "string_constexpr.00000357.hpp"
#include "string_constexpr.00000358.hpp"
#include "string_constexpr.00000359.hpp"
#include "string_constexpr.00000360.hpp"
#include "string_constexpr.00000361.hpp"
#include "string_constexpr.00000362.hpp"
#include "string_constexpr.00000363.hpp"
#include "string_constexpr.00000364.hpp"
#include "string_constexpr.00000365.hpp"
#include "string_constexpr.00000366.hpp"
#include "string_constexpr.00000367.hpp"
#include "string_constexpr.00000368.hpp"
#include "string_constexpr.00000369.hpp"
#include "string_constexpr.00000370.hpp"
#include "string_constexpr.00000371.hpp"
#include "string_constexpr.00000372.hpp"
#include "string_constexpr.00000373.hpp"
#include "string_constexpr.00000374.hpp"
#include "string_constexpr.00000375.hpp"
#include "string_constexpr.00000376.hpp"
#include "string_constexpr.00000377.hpp"
#include "string_constexpr.00000378.hpp"
#include "string_constexpr.00000379.hpp"
#include "string_constexpr.00000380.hpp"
#include "string_constexpr.00000381.hpp"
#include "string_constexpr.00000382.hpp"
#include "string_constexpr.00000383.hpp"
#include "string_constexpr.00000384.hpp"
#include "string_constexpr.00000385.hpp"
#include "string_constexpr.00000386.hpp"
#include "string_constexpr.00000387.hpp"
#include "string_constexpr.00000388.hpp"
#include "string_constexpr.00000389.hpp"
#include "string_constexpr.00000390.hpp"
#include "string_constexpr.00000391.hpp"
#include "string_constexpr.00000392.hpp"
#include "string_constexpr.00000393.hpp"
#include "string_constexpr.00000394.hpp"
#include "string_constexpr.00000395.hpp"
#include "string_constexpr.00000396.hpp"
#include "string_constexpr.00000397.hpp"
#include "string_constexpr.00000398.hpp"
#include "string_constexpr.00000399.hpp"
#include "string_constexpr.00000400.hpp"
#include "string_constexpr.00000401.hpp"
#include "string_constexpr.00000402.hpp"
#include "string_constexpr.00000403.hpp"
#include "string_constexpr.00000404.hpp"
#include "string_constexpr.00000405.hpp"
#include "string_constexpr.00000406.hpp"
#include "string_constexpr.00000407.hpp"
#include "string_constexpr.00000408.hpp"
#include "string_constexpr.00000409.hpp"
#include "string_constexpr.00000410.hpp"
#include "string_constexpr.00000411.hpp"
#include "string_constexpr.00000412.hpp"
#include "string_constexpr.00000413.hpp"
#include "string_constexpr.00000414.hpp"
#include "string_constexpr.00000415.hpp"
#include "string_constexpr.00000416.hpp"
#include "string_constexpr.00000417.hpp"
#include "string_constexpr.00000418.hpp"
#include "string_constexpr.00000419.hpp"
#include "string_constexpr.00000420.hpp"
#include "string_constexpr.00000421.hpp"
#include "string_constexpr.00000422.hpp"
#include "string_constexpr.00000423.hpp"
#include "string_constexpr.00000424.hpp"
#include "string_constexpr.00000425.hpp"
#include "string_constexpr.00000426.hpp"
#include "string_constexpr.00000427.hpp"
#include "string_constexpr.00000428.hpp"
#include "string_constexpr.00000429.hpp"
#include "string_constexpr.00000430.hpp"
#include "string_constexpr.00000431.hpp"
#include "string_constexpr.00000432.hpp"
#include "string_constexpr.00000433.hpp"
#include "string_constexpr.00000434.hpp"
#include "string_constexpr.00000435.hpp"
#include "string_constexpr.00000436.hpp"
#include "string_constexpr.00000437.hpp"
#include "string_constexpr.00000438.hpp"
#include "string_constexpr.00000439.hpp"
#include "string_constexpr.00000440.hpp"
#include "string_constexpr.00000441.hpp"
#include "string_constexpr.00000442.hpp"
#include "string_constexpr.00000443.hpp"
#include "string_constexpr.00000444.hpp"
#include "string_constexpr.00000445.hpp"
#include "string_constexpr.00000446.hpp"
#include "string_constexpr.00000447.hpp"
#include "string_constexpr.00000448.hpp"
#include "string_constexpr.00000449.hpp"
#include "string_constexpr.00000450.hpp"
#include "string_constexpr.00000451.hpp"
#include "string_constexpr.00000452.hpp"
#include "string_constexpr.00000453.hpp"
#include "string_constexpr.00000454.hpp"
#include "string_constexpr.00000455.hpp"
#include "string_constexpr.00000456.hpp"
#include "string_constexpr.00000457.hpp"
#include "string_constexpr.00000458.hpp"
#include "string_constexpr.00000459.hpp"
#include "string_constexpr.00000460.hpp"
#include "string_constexpr.00000461.hpp"
#include "string_constexpr.00000462.hpp"
#include "string_constexpr.00000463.hpp"
#include "string_constexpr.00000464.hpp"
#include "string_constexpr.00000465.hpp"
#include "string_constexpr.00000466.hpp"
#include "string_constexpr.00000467.hpp"
#include "string_constexpr.00000468.hpp"
#include "string_constexpr.00000469.hpp"
#include "string_constexpr.00000470.hpp"
#include "string_constexpr.00000471.hpp"
#include "string_constexpr.00000472.hpp"
#include "string_constexpr.00000473.hpp"
#include "string_constexpr.00000474.hpp"
#include "string_constexpr.00000475.hpp"
#include "string_constexpr.00000476.hpp"
#include "string_constexpr.00000477.hpp"
#include "string_constexpr.00000478.hpp"
#include "string_constexpr.00000479.hpp"
#include "string_constexpr.00000480.hpp"
#include "string_constexpr.00000481.hpp"
#include "string_constexpr.00000482.hpp"
#include "string_constexpr.00000483.hpp"
#include "string_constexpr.00000484.hpp"
#include "string_constexpr.00000485.hpp"
#include "string_constexpr.00000486.hpp"
#include "string_constexpr.00000487.hpp"
#include "string_constexpr.00000488.hpp"
#include "string_constexpr.00000489.hpp"
#include "string_constexpr.00000490.hpp"
#include "string_constexpr.00000491.hpp"
#include "string_constexpr.00000492.hpp"
#include "string_constexpr.00000493.hpp"
#include "string_constexpr.00000494.hpp"
#include "string_constexpr.00000495.hpp"
#include "string_constexpr.00000496.hpp"
#include "string_constexpr.00000497.hpp"
#include "string_constexpr.00000498.hpp"
#include "string_constexpr.00000499.hpp"
#include "string_constexpr.00000500.hpp"
#include "string_constexpr.00000501.hpp"
#include "string_constexpr.00000502.hpp"
#include "string_constexpr.00000503.hpp"
#include "string_constexpr.00000504.hpp"
#include "string_constexpr.00000505.hpp"
#include "string_constexpr.00000506.hpp"
#include "string_constexpr.00000507.hpp"
#include "string_constexpr.00000508.hpp"
#include "string_constexpr.00000509.hpp"
#include "string_constexpr.00000510.hpp"
#include "string_constexpr.00000511.hpp"

}/*namespace _detail_sstd_string*/

 
}/*namespace sstd*/

 


#ifndef _sstd_key_at
#define _sstd_key_at(_POS_SSTD_,...) ((_POS_SSTD_)<(sizeof(__VA_ARGS__))?(__VA_ARGS__[_POS_SSTD_]):char(0))
#endif

#ifndef sstd_cstr
#define sstd_cstr(...) ::sstd::_detail_sstd_string::string_constexpr_builder_helper< (sizeof(__VA_ARGS__)-1)  \
,_sstd_key_at( 0 ,__VA_ARGS__)  ,_sstd_key_at( 1 ,__VA_ARGS__)  ,_sstd_key_at( 2 ,__VA_ARGS__)  ,_sstd_key_at( 3 ,__VA_ARGS__)  ,_sstd_key_at( 4 ,__VA_ARGS__)  ,_sstd_key_at( 5 ,__VA_ARGS__)  ,_sstd_key_at( 6 ,__VA_ARGS__)  ,_sstd_key_at( 7 ,__VA_ARGS__)  ,_sstd_key_at( 8 ,__VA_ARGS__)  ,_sstd_key_at( 9 ,__VA_ARGS__)  ,_sstd_key_at( 10 ,__VA_ARGS__)  ,_sstd_key_at( 11 ,__VA_ARGS__)  ,_sstd_key_at( 12 ,__VA_ARGS__)  ,_sstd_key_at( 13 ,__VA_ARGS__)  ,_sstd_key_at( 14 ,__VA_ARGS__)  ,_sstd_key_at( 15 ,__VA_ARGS__)  ,_sstd_key_at( 16 ,__VA_ARGS__)  ,_sstd_key_at( 17 ,__VA_ARGS__)  ,_sstd_key_at( 18 ,__VA_ARGS__)  ,_sstd_key_at( 19 ,__VA_ARGS__)  ,_sstd_key_at( 20 ,__VA_ARGS__)  ,_sstd_key_at( 21 ,__VA_ARGS__)  ,_sstd_key_at( 22 ,__VA_ARGS__)  ,_sstd_key_at( 23 ,__VA_ARGS__)  ,_sstd_key_at( 24 ,__VA_ARGS__)  ,_sstd_key_at( 25 ,__VA_ARGS__)  ,_sstd_key_at( 26 ,__VA_ARGS__)  ,_sstd_key_at( 27 ,__VA_ARGS__)  ,_sstd_key_at( 28 ,__VA_ARGS__)  ,_sstd_key_at( 29 ,__VA_ARGS__)  ,_sstd_key_at( 30 ,__VA_ARGS__)  ,_sstd_key_at( 31 ,__VA_ARGS__)  ,_sstd_key_at( 32 ,__VA_ARGS__)  ,_sstd_key_at( 33 ,__VA_ARGS__)  ,_sstd_key_at( 34 ,__VA_ARGS__)  ,_sstd_key_at( 35 ,__VA_ARGS__)  ,_sstd_key_at( 36 ,__VA_ARGS__)  ,_sstd_key_at( 37 ,__VA_ARGS__)  ,_sstd_key_at( 38 ,__VA_ARGS__)  ,_sstd_key_at( 39 ,__VA_ARGS__)  ,_sstd_key_at( 40 ,__VA_ARGS__)  ,_sstd_key_at( 41 ,__VA_ARGS__)  ,_sstd_key_at( 42 ,__VA_ARGS__)  ,_sstd_key_at( 43 ,__VA_ARGS__)  ,_sstd_key_at( 44 ,__VA_ARGS__)  ,_sstd_key_at( 45 ,__VA_ARGS__)  ,_sstd_key_at( 46 ,__VA_ARGS__)  ,_sstd_key_at( 47 ,__VA_ARGS__)  ,_sstd_key_at( 48 ,__VA_ARGS__)  ,_sstd_key_at( 49 ,__VA_ARGS__)  ,_sstd_key_at( 50 ,__VA_ARGS__)  ,_sstd_key_at( 51 ,__VA_ARGS__)  ,_sstd_key_at( 52 ,__VA_ARGS__)  ,_sstd_key_at( 53 ,__VA_ARGS__)  ,_sstd_key_at( 54 ,__VA_ARGS__)  ,_sstd_key_at( 55 ,__VA_ARGS__)  ,_sstd_key_at( 56 ,__VA_ARGS__)  ,_sstd_key_at( 57 ,__VA_ARGS__)  ,_sstd_key_at( 58 ,__VA_ARGS__)  ,_sstd_key_at( 59 ,__VA_ARGS__)  ,_sstd_key_at( 60 ,__VA_ARGS__)  ,_sstd_key_at( 61 ,__VA_ARGS__)  ,_sstd_key_at( 62 ,__VA_ARGS__)  ,_sstd_key_at( 63 ,__VA_ARGS__)  ,_sstd_key_at( 64 ,__VA_ARGS__)   \
,_sstd_key_at( 65 ,__VA_ARGS__)  ,_sstd_key_at( 66 ,__VA_ARGS__)  ,_sstd_key_at( 67 ,__VA_ARGS__)  ,_sstd_key_at( 68 ,__VA_ARGS__)  ,_sstd_key_at( 69 ,__VA_ARGS__)  ,_sstd_key_at( 70 ,__VA_ARGS__)  ,_sstd_key_at( 71 ,__VA_ARGS__)  ,_sstd_key_at( 72 ,__VA_ARGS__)  ,_sstd_key_at( 73 ,__VA_ARGS__)  ,_sstd_key_at( 74 ,__VA_ARGS__)  ,_sstd_key_at( 75 ,__VA_ARGS__)  ,_sstd_key_at( 76 ,__VA_ARGS__)  ,_sstd_key_at( 77 ,__VA_ARGS__)  ,_sstd_key_at( 78 ,__VA_ARGS__)  ,_sstd_key_at( 79 ,__VA_ARGS__)  ,_sstd_key_at( 80 ,__VA_ARGS__)  ,_sstd_key_at( 81 ,__VA_ARGS__)  ,_sstd_key_at( 82 ,__VA_ARGS__)  ,_sstd_key_at( 83 ,__VA_ARGS__)  ,_sstd_key_at( 84 ,__VA_ARGS__)  ,_sstd_key_at( 85 ,__VA_ARGS__)  ,_sstd_key_at( 86 ,__VA_ARGS__)  ,_sstd_key_at( 87 ,__VA_ARGS__)  ,_sstd_key_at( 88 ,__VA_ARGS__)  ,_sstd_key_at( 89 ,__VA_ARGS__)  ,_sstd_key_at( 90 ,__VA_ARGS__)  ,_sstd_key_at( 91 ,__VA_ARGS__)  ,_sstd_key_at( 92 ,__VA_ARGS__)  ,_sstd_key_at( 93 ,__VA_ARGS__)  ,_sstd_key_at( 94 ,__VA_ARGS__)  ,_sstd_key_at( 95 ,__VA_ARGS__)  ,_sstd_key_at( 96 ,__VA_ARGS__)  ,_sstd_key_at( 97 ,__VA_ARGS__)  ,_sstd_key_at( 98 ,__VA_ARGS__)  ,_sstd_key_at( 99 ,__VA_ARGS__)  ,_sstd_key_at( 100 ,__VA_ARGS__)  ,_sstd_key_at( 101 ,__VA_ARGS__)  ,_sstd_key_at( 102 ,__VA_ARGS__)  ,_sstd_key_at( 103 ,__VA_ARGS__)  ,_sstd_key_at( 104 ,__VA_ARGS__)  ,_sstd_key_at( 105 ,__VA_ARGS__)  ,_sstd_key_at( 106 ,__VA_ARGS__)  ,_sstd_key_at( 107 ,__VA_ARGS__)  ,_sstd_key_at( 108 ,__VA_ARGS__)  ,_sstd_key_at( 109 ,__VA_ARGS__)  ,_sstd_key_at( 110 ,__VA_ARGS__)  ,_sstd_key_at( 111 ,__VA_ARGS__)  ,_sstd_key_at( 112 ,__VA_ARGS__)  ,_sstd_key_at( 113 ,__VA_ARGS__)  ,_sstd_key_at( 114 ,__VA_ARGS__)  ,_sstd_key_at( 115 ,__VA_ARGS__)  ,_sstd_key_at( 116 ,__VA_ARGS__)  ,_sstd_key_at( 117 ,__VA_ARGS__)  ,_sstd_key_at( 118 ,__VA_ARGS__)  ,_sstd_key_at( 119 ,__VA_ARGS__)  ,_sstd_key_at( 120 ,__VA_ARGS__)  ,_sstd_key_at( 121 ,__VA_ARGS__)  ,_sstd_key_at( 122 ,__VA_ARGS__)  ,_sstd_key_at( 123 ,__VA_ARGS__)  ,_sstd_key_at( 124 ,__VA_ARGS__)  ,_sstd_key_at( 125 ,__VA_ARGS__)  ,_sstd_key_at( 126 ,__VA_ARGS__)  ,_sstd_key_at( 127 ,__VA_ARGS__)  ,_sstd_key_at( 128 ,__VA_ARGS__)   \
,_sstd_key_at( 129 ,__VA_ARGS__)  ,_sstd_key_at( 130 ,__VA_ARGS__)  ,_sstd_key_at( 131 ,__VA_ARGS__)  ,_sstd_key_at( 132 ,__VA_ARGS__)  ,_sstd_key_at( 133 ,__VA_ARGS__)  ,_sstd_key_at( 134 ,__VA_ARGS__)  ,_sstd_key_at( 135 ,__VA_ARGS__)  ,_sstd_key_at( 136 ,__VA_ARGS__)  ,_sstd_key_at( 137 ,__VA_ARGS__)  ,_sstd_key_at( 138 ,__VA_ARGS__)  ,_sstd_key_at( 139 ,__VA_ARGS__)  ,_sstd_key_at( 140 ,__VA_ARGS__)  ,_sstd_key_at( 141 ,__VA_ARGS__)  ,_sstd_key_at( 142 ,__VA_ARGS__)  ,_sstd_key_at( 143 ,__VA_ARGS__)  ,_sstd_key_at( 144 ,__VA_ARGS__)  ,_sstd_key_at( 145 ,__VA_ARGS__)  ,_sstd_key_at( 146 ,__VA_ARGS__)  ,_sstd_key_at( 147 ,__VA_ARGS__)  ,_sstd_key_at( 148 ,__VA_ARGS__)  ,_sstd_key_at( 149 ,__VA_ARGS__)  ,_sstd_key_at( 150 ,__VA_ARGS__)  ,_sstd_key_at( 151 ,__VA_ARGS__)  ,_sstd_key_at( 152 ,__VA_ARGS__)  ,_sstd_key_at( 153 ,__VA_ARGS__)  ,_sstd_key_at( 154 ,__VA_ARGS__)  ,_sstd_key_at( 155 ,__VA_ARGS__)  ,_sstd_key_at( 156 ,__VA_ARGS__)  ,_sstd_key_at( 157 ,__VA_ARGS__)  ,_sstd_key_at( 158 ,__VA_ARGS__)  ,_sstd_key_at( 159 ,__VA_ARGS__)  ,_sstd_key_at( 160 ,__VA_ARGS__)  ,_sstd_key_at( 161 ,__VA_ARGS__)  ,_sstd_key_at( 162 ,__VA_ARGS__)  ,_sstd_key_at( 163 ,__VA_ARGS__)  ,_sstd_key_at( 164 ,__VA_ARGS__)  ,_sstd_key_at( 165 ,__VA_ARGS__)  ,_sstd_key_at( 166 ,__VA_ARGS__)  ,_sstd_key_at( 167 ,__VA_ARGS__)  ,_sstd_key_at( 168 ,__VA_ARGS__)  ,_sstd_key_at( 169 ,__VA_ARGS__)  ,_sstd_key_at( 170 ,__VA_ARGS__)  ,_sstd_key_at( 171 ,__VA_ARGS__)  ,_sstd_key_at( 172 ,__VA_ARGS__)  ,_sstd_key_at( 173 ,__VA_ARGS__)  ,_sstd_key_at( 174 ,__VA_ARGS__)  ,_sstd_key_at( 175 ,__VA_ARGS__)  ,_sstd_key_at( 176 ,__VA_ARGS__)  ,_sstd_key_at( 177 ,__VA_ARGS__)  ,_sstd_key_at( 178 ,__VA_ARGS__)  ,_sstd_key_at( 179 ,__VA_ARGS__)  ,_sstd_key_at( 180 ,__VA_ARGS__)  ,_sstd_key_at( 181 ,__VA_ARGS__)  ,_sstd_key_at( 182 ,__VA_ARGS__)  ,_sstd_key_at( 183 ,__VA_ARGS__)  ,_sstd_key_at( 184 ,__VA_ARGS__)  ,_sstd_key_at( 185 ,__VA_ARGS__)  ,_sstd_key_at( 186 ,__VA_ARGS__)  ,_sstd_key_at( 187 ,__VA_ARGS__)  ,_sstd_key_at( 188 ,__VA_ARGS__)  ,_sstd_key_at( 189 ,__VA_ARGS__)  ,_sstd_key_at( 190 ,__VA_ARGS__)  ,_sstd_key_at( 191 ,__VA_ARGS__)  ,_sstd_key_at( 192 ,__VA_ARGS__)   \
,_sstd_key_at( 193 ,__VA_ARGS__)  ,_sstd_key_at( 194 ,__VA_ARGS__)  ,_sstd_key_at( 195 ,__VA_ARGS__)  ,_sstd_key_at( 196 ,__VA_ARGS__)  ,_sstd_key_at( 197 ,__VA_ARGS__)  ,_sstd_key_at( 198 ,__VA_ARGS__)  ,_sstd_key_at( 199 ,__VA_ARGS__)  ,_sstd_key_at( 200 ,__VA_ARGS__)  ,_sstd_key_at( 201 ,__VA_ARGS__)  ,_sstd_key_at( 202 ,__VA_ARGS__)  ,_sstd_key_at( 203 ,__VA_ARGS__)  ,_sstd_key_at( 204 ,__VA_ARGS__)  ,_sstd_key_at( 205 ,__VA_ARGS__)  ,_sstd_key_at( 206 ,__VA_ARGS__)  ,_sstd_key_at( 207 ,__VA_ARGS__)  ,_sstd_key_at( 208 ,__VA_ARGS__)  ,_sstd_key_at( 209 ,__VA_ARGS__)  ,_sstd_key_at( 210 ,__VA_ARGS__)  ,_sstd_key_at( 211 ,__VA_ARGS__)  ,_sstd_key_at( 212 ,__VA_ARGS__)  ,_sstd_key_at( 213 ,__VA_ARGS__)  ,_sstd_key_at( 214 ,__VA_ARGS__)  ,_sstd_key_at( 215 ,__VA_ARGS__)  ,_sstd_key_at( 216 ,__VA_ARGS__)  ,_sstd_key_at( 217 ,__VA_ARGS__)  ,_sstd_key_at( 218 ,__VA_ARGS__)  ,_sstd_key_at( 219 ,__VA_ARGS__)  ,_sstd_key_at( 220 ,__VA_ARGS__)  ,_sstd_key_at( 221 ,__VA_ARGS__)  ,_sstd_key_at( 222 ,__VA_ARGS__)  ,_sstd_key_at( 223 ,__VA_ARGS__)  ,_sstd_key_at( 224 ,__VA_ARGS__)  ,_sstd_key_at( 225 ,__VA_ARGS__)  ,_sstd_key_at( 226 ,__VA_ARGS__)  ,_sstd_key_at( 227 ,__VA_ARGS__)  ,_sstd_key_at( 228 ,__VA_ARGS__)  ,_sstd_key_at( 229 ,__VA_ARGS__)  ,_sstd_key_at( 230 ,__VA_ARGS__)  ,_sstd_key_at( 231 ,__VA_ARGS__)  ,_sstd_key_at( 232 ,__VA_ARGS__)  ,_sstd_key_at( 233 ,__VA_ARGS__)  ,_sstd_key_at( 234 ,__VA_ARGS__)  ,_sstd_key_at( 235 ,__VA_ARGS__)  ,_sstd_key_at( 236 ,__VA_ARGS__)  ,_sstd_key_at( 237 ,__VA_ARGS__)  ,_sstd_key_at( 238 ,__VA_ARGS__)  ,_sstd_key_at( 239 ,__VA_ARGS__)  ,_sstd_key_at( 240 ,__VA_ARGS__)  ,_sstd_key_at( 241 ,__VA_ARGS__)  ,_sstd_key_at( 242 ,__VA_ARGS__)  ,_sstd_key_at( 243 ,__VA_ARGS__)  ,_sstd_key_at( 244 ,__VA_ARGS__)  ,_sstd_key_at( 245 ,__VA_ARGS__)  ,_sstd_key_at( 246 ,__VA_ARGS__)  ,_sstd_key_at( 247 ,__VA_ARGS__)  ,_sstd_key_at( 248 ,__VA_ARGS__)  ,_sstd_key_at( 249 ,__VA_ARGS__)  ,_sstd_key_at( 250 ,__VA_ARGS__)  ,_sstd_key_at( 251 ,__VA_ARGS__)  ,_sstd_key_at( 252 ,__VA_ARGS__)  ,_sstd_key_at( 253 ,__VA_ARGS__)  ,_sstd_key_at( 254 ,__VA_ARGS__)  ,_sstd_key_at( 255 ,__VA_ARGS__)  ,_sstd_key_at( 256 ,__VA_ARGS__)   \
,_sstd_key_at( 257 ,__VA_ARGS__)  ,_sstd_key_at( 258 ,__VA_ARGS__)  ,_sstd_key_at( 259 ,__VA_ARGS__)  ,_sstd_key_at( 260 ,__VA_ARGS__)  ,_sstd_key_at( 261 ,__VA_ARGS__)  ,_sstd_key_at( 262 ,__VA_ARGS__)  ,_sstd_key_at( 263 ,__VA_ARGS__)  ,_sstd_key_at( 264 ,__VA_ARGS__)  ,_sstd_key_at( 265 ,__VA_ARGS__)  ,_sstd_key_at( 266 ,__VA_ARGS__)  ,_sstd_key_at( 267 ,__VA_ARGS__)  ,_sstd_key_at( 268 ,__VA_ARGS__)  ,_sstd_key_at( 269 ,__VA_ARGS__)  ,_sstd_key_at( 270 ,__VA_ARGS__)  ,_sstd_key_at( 271 ,__VA_ARGS__)  ,_sstd_key_at( 272 ,__VA_ARGS__)  ,_sstd_key_at( 273 ,__VA_ARGS__)  ,_sstd_key_at( 274 ,__VA_ARGS__)  ,_sstd_key_at( 275 ,__VA_ARGS__)  ,_sstd_key_at( 276 ,__VA_ARGS__)  ,_sstd_key_at( 277 ,__VA_ARGS__)  ,_sstd_key_at( 278 ,__VA_ARGS__)  ,_sstd_key_at( 279 ,__VA_ARGS__)  ,_sstd_key_at( 280 ,__VA_ARGS__)  ,_sstd_key_at( 281 ,__VA_ARGS__)  ,_sstd_key_at( 282 ,__VA_ARGS__)  ,_sstd_key_at( 283 ,__VA_ARGS__)  ,_sstd_key_at( 284 ,__VA_ARGS__)  ,_sstd_key_at( 285 ,__VA_ARGS__)  ,_sstd_key_at( 286 ,__VA_ARGS__)  ,_sstd_key_at( 287 ,__VA_ARGS__)  ,_sstd_key_at( 288 ,__VA_ARGS__)  ,_sstd_key_at( 289 ,__VA_ARGS__)  ,_sstd_key_at( 290 ,__VA_ARGS__)  ,_sstd_key_at( 291 ,__VA_ARGS__)  ,_sstd_key_at( 292 ,__VA_ARGS__)  ,_sstd_key_at( 293 ,__VA_ARGS__)  ,_sstd_key_at( 294 ,__VA_ARGS__)  ,_sstd_key_at( 295 ,__VA_ARGS__)  ,_sstd_key_at( 296 ,__VA_ARGS__)  ,_sstd_key_at( 297 ,__VA_ARGS__)  ,_sstd_key_at( 298 ,__VA_ARGS__)  ,_sstd_key_at( 299 ,__VA_ARGS__)  ,_sstd_key_at( 300 ,__VA_ARGS__)  ,_sstd_key_at( 301 ,__VA_ARGS__)  ,_sstd_key_at( 302 ,__VA_ARGS__)  ,_sstd_key_at( 303 ,__VA_ARGS__)  ,_sstd_key_at( 304 ,__VA_ARGS__)  ,_sstd_key_at( 305 ,__VA_ARGS__)  ,_sstd_key_at( 306 ,__VA_ARGS__)  ,_sstd_key_at( 307 ,__VA_ARGS__)  ,_sstd_key_at( 308 ,__VA_ARGS__)  ,_sstd_key_at( 309 ,__VA_ARGS__)  ,_sstd_key_at( 310 ,__VA_ARGS__)  ,_sstd_key_at( 311 ,__VA_ARGS__)  ,_sstd_key_at( 312 ,__VA_ARGS__)  ,_sstd_key_at( 313 ,__VA_ARGS__)  ,_sstd_key_at( 314 ,__VA_ARGS__)  ,_sstd_key_at( 315 ,__VA_ARGS__)  ,_sstd_key_at( 316 ,__VA_ARGS__)  ,_sstd_key_at( 317 ,__VA_ARGS__)  ,_sstd_key_at( 318 ,__VA_ARGS__)  ,_sstd_key_at( 319 ,__VA_ARGS__)  ,_sstd_key_at( 320 ,__VA_ARGS__)   \
,_sstd_key_at( 321 ,__VA_ARGS__)  ,_sstd_key_at( 322 ,__VA_ARGS__)  ,_sstd_key_at( 323 ,__VA_ARGS__)  ,_sstd_key_at( 324 ,__VA_ARGS__)  ,_sstd_key_at( 325 ,__VA_ARGS__)  ,_sstd_key_at( 326 ,__VA_ARGS__)  ,_sstd_key_at( 327 ,__VA_ARGS__)  ,_sstd_key_at( 328 ,__VA_ARGS__)  ,_sstd_key_at( 329 ,__VA_ARGS__)  ,_sstd_key_at( 330 ,__VA_ARGS__)  ,_sstd_key_at( 331 ,__VA_ARGS__)  ,_sstd_key_at( 332 ,__VA_ARGS__)  ,_sstd_key_at( 333 ,__VA_ARGS__)  ,_sstd_key_at( 334 ,__VA_ARGS__)  ,_sstd_key_at( 335 ,__VA_ARGS__)  ,_sstd_key_at( 336 ,__VA_ARGS__)  ,_sstd_key_at( 337 ,__VA_ARGS__)  ,_sstd_key_at( 338 ,__VA_ARGS__)  ,_sstd_key_at( 339 ,__VA_ARGS__)  ,_sstd_key_at( 340 ,__VA_ARGS__)  ,_sstd_key_at( 341 ,__VA_ARGS__)  ,_sstd_key_at( 342 ,__VA_ARGS__)  ,_sstd_key_at( 343 ,__VA_ARGS__)  ,_sstd_key_at( 344 ,__VA_ARGS__)  ,_sstd_key_at( 345 ,__VA_ARGS__)  ,_sstd_key_at( 346 ,__VA_ARGS__)  ,_sstd_key_at( 347 ,__VA_ARGS__)  ,_sstd_key_at( 348 ,__VA_ARGS__)  ,_sstd_key_at( 349 ,__VA_ARGS__)  ,_sstd_key_at( 350 ,__VA_ARGS__)  ,_sstd_key_at( 351 ,__VA_ARGS__)  ,_sstd_key_at( 352 ,__VA_ARGS__)  ,_sstd_key_at( 353 ,__VA_ARGS__)  ,_sstd_key_at( 354 ,__VA_ARGS__)  ,_sstd_key_at( 355 ,__VA_ARGS__)  ,_sstd_key_at( 356 ,__VA_ARGS__)  ,_sstd_key_at( 357 ,__VA_ARGS__)  ,_sstd_key_at( 358 ,__VA_ARGS__)  ,_sstd_key_at( 359 ,__VA_ARGS__)  ,_sstd_key_at( 360 ,__VA_ARGS__)  ,_sstd_key_at( 361 ,__VA_ARGS__)  ,_sstd_key_at( 362 ,__VA_ARGS__)  ,_sstd_key_at( 363 ,__VA_ARGS__)  ,_sstd_key_at( 364 ,__VA_ARGS__)  ,_sstd_key_at( 365 ,__VA_ARGS__)  ,_sstd_key_at( 366 ,__VA_ARGS__)  ,_sstd_key_at( 367 ,__VA_ARGS__)  ,_sstd_key_at( 368 ,__VA_ARGS__)  ,_sstd_key_at( 369 ,__VA_ARGS__)  ,_sstd_key_at( 370 ,__VA_ARGS__)  ,_sstd_key_at( 371 ,__VA_ARGS__)  ,_sstd_key_at( 372 ,__VA_ARGS__)  ,_sstd_key_at( 373 ,__VA_ARGS__)  ,_sstd_key_at( 374 ,__VA_ARGS__)  ,_sstd_key_at( 375 ,__VA_ARGS__)  ,_sstd_key_at( 376 ,__VA_ARGS__)  ,_sstd_key_at( 377 ,__VA_ARGS__)  ,_sstd_key_at( 378 ,__VA_ARGS__)  ,_sstd_key_at( 379 ,__VA_ARGS__)  ,_sstd_key_at( 380 ,__VA_ARGS__)  ,_sstd_key_at( 381 ,__VA_ARGS__)  ,_sstd_key_at( 382 ,__VA_ARGS__)  ,_sstd_key_at( 383 ,__VA_ARGS__)  ,_sstd_key_at( 384 ,__VA_ARGS__)   \
,_sstd_key_at( 385 ,__VA_ARGS__)  ,_sstd_key_at( 386 ,__VA_ARGS__)  ,_sstd_key_at( 387 ,__VA_ARGS__)  ,_sstd_key_at( 388 ,__VA_ARGS__)  ,_sstd_key_at( 389 ,__VA_ARGS__)  ,_sstd_key_at( 390 ,__VA_ARGS__)  ,_sstd_key_at( 391 ,__VA_ARGS__)  ,_sstd_key_at( 392 ,__VA_ARGS__)  ,_sstd_key_at( 393 ,__VA_ARGS__)  ,_sstd_key_at( 394 ,__VA_ARGS__)  ,_sstd_key_at( 395 ,__VA_ARGS__)  ,_sstd_key_at( 396 ,__VA_ARGS__)  ,_sstd_key_at( 397 ,__VA_ARGS__)  ,_sstd_key_at( 398 ,__VA_ARGS__)  ,_sstd_key_at( 399 ,__VA_ARGS__)  ,_sstd_key_at( 400 ,__VA_ARGS__)  ,_sstd_key_at( 401 ,__VA_ARGS__)  ,_sstd_key_at( 402 ,__VA_ARGS__)  ,_sstd_key_at( 403 ,__VA_ARGS__)  ,_sstd_key_at( 404 ,__VA_ARGS__)  ,_sstd_key_at( 405 ,__VA_ARGS__)  ,_sstd_key_at( 406 ,__VA_ARGS__)  ,_sstd_key_at( 407 ,__VA_ARGS__)  ,_sstd_key_at( 408 ,__VA_ARGS__)  ,_sstd_key_at( 409 ,__VA_ARGS__)  ,_sstd_key_at( 410 ,__VA_ARGS__)  ,_sstd_key_at( 411 ,__VA_ARGS__)  ,_sstd_key_at( 412 ,__VA_ARGS__)  ,_sstd_key_at( 413 ,__VA_ARGS__)  ,_sstd_key_at( 414 ,__VA_ARGS__)  ,_sstd_key_at( 415 ,__VA_ARGS__)  ,_sstd_key_at( 416 ,__VA_ARGS__)  ,_sstd_key_at( 417 ,__VA_ARGS__)  ,_sstd_key_at( 418 ,__VA_ARGS__)  ,_sstd_key_at( 419 ,__VA_ARGS__)  ,_sstd_key_at( 420 ,__VA_ARGS__)  ,_sstd_key_at( 421 ,__VA_ARGS__)  ,_sstd_key_at( 422 ,__VA_ARGS__)  ,_sstd_key_at( 423 ,__VA_ARGS__)  ,_sstd_key_at( 424 ,__VA_ARGS__)  ,_sstd_key_at( 425 ,__VA_ARGS__)  ,_sstd_key_at( 426 ,__VA_ARGS__)  ,_sstd_key_at( 427 ,__VA_ARGS__)  ,_sstd_key_at( 428 ,__VA_ARGS__)  ,_sstd_key_at( 429 ,__VA_ARGS__)  ,_sstd_key_at( 430 ,__VA_ARGS__)  ,_sstd_key_at( 431 ,__VA_ARGS__)  ,_sstd_key_at( 432 ,__VA_ARGS__)  ,_sstd_key_at( 433 ,__VA_ARGS__)  ,_sstd_key_at( 434 ,__VA_ARGS__)  ,_sstd_key_at( 435 ,__VA_ARGS__)  ,_sstd_key_at( 436 ,__VA_ARGS__)  ,_sstd_key_at( 437 ,__VA_ARGS__)  ,_sstd_key_at( 438 ,__VA_ARGS__)  ,_sstd_key_at( 439 ,__VA_ARGS__)  ,_sstd_key_at( 440 ,__VA_ARGS__)  ,_sstd_key_at( 441 ,__VA_ARGS__)  ,_sstd_key_at( 442 ,__VA_ARGS__)  ,_sstd_key_at( 443 ,__VA_ARGS__)  ,_sstd_key_at( 444 ,__VA_ARGS__)  ,_sstd_key_at( 445 ,__VA_ARGS__)  ,_sstd_key_at( 446 ,__VA_ARGS__)  ,_sstd_key_at( 447 ,__VA_ARGS__)  ,_sstd_key_at( 448 ,__VA_ARGS__)   \
,_sstd_key_at( 449 ,__VA_ARGS__)  ,_sstd_key_at( 450 ,__VA_ARGS__)  ,_sstd_key_at( 451 ,__VA_ARGS__)  ,_sstd_key_at( 452 ,__VA_ARGS__)  ,_sstd_key_at( 453 ,__VA_ARGS__)  ,_sstd_key_at( 454 ,__VA_ARGS__)  ,_sstd_key_at( 455 ,__VA_ARGS__)  ,_sstd_key_at( 456 ,__VA_ARGS__)  ,_sstd_key_at( 457 ,__VA_ARGS__)  ,_sstd_key_at( 458 ,__VA_ARGS__)  ,_sstd_key_at( 459 ,__VA_ARGS__)  ,_sstd_key_at( 460 ,__VA_ARGS__)  ,_sstd_key_at( 461 ,__VA_ARGS__)  ,_sstd_key_at( 462 ,__VA_ARGS__)  ,_sstd_key_at( 463 ,__VA_ARGS__)  ,_sstd_key_at( 464 ,__VA_ARGS__)  ,_sstd_key_at( 465 ,__VA_ARGS__)  ,_sstd_key_at( 466 ,__VA_ARGS__)  ,_sstd_key_at( 467 ,__VA_ARGS__)  ,_sstd_key_at( 468 ,__VA_ARGS__)  ,_sstd_key_at( 469 ,__VA_ARGS__)  ,_sstd_key_at( 470 ,__VA_ARGS__)  ,_sstd_key_at( 471 ,__VA_ARGS__)  ,_sstd_key_at( 472 ,__VA_ARGS__)  ,_sstd_key_at( 473 ,__VA_ARGS__)  ,_sstd_key_at( 474 ,__VA_ARGS__)  ,_sstd_key_at( 475 ,__VA_ARGS__)  ,_sstd_key_at( 476 ,__VA_ARGS__)  ,_sstd_key_at( 477 ,__VA_ARGS__)  ,_sstd_key_at( 478 ,__VA_ARGS__)  ,_sstd_key_at( 479 ,__VA_ARGS__)  ,_sstd_key_at( 480 ,__VA_ARGS__)  ,_sstd_key_at( 481 ,__VA_ARGS__)  ,_sstd_key_at( 482 ,__VA_ARGS__)  ,_sstd_key_at( 483 ,__VA_ARGS__)  ,_sstd_key_at( 484 ,__VA_ARGS__)  ,_sstd_key_at( 485 ,__VA_ARGS__)  ,_sstd_key_at( 486 ,__VA_ARGS__)  ,_sstd_key_at( 487 ,__VA_ARGS__)  ,_sstd_key_at( 488 ,__VA_ARGS__)  ,_sstd_key_at( 489 ,__VA_ARGS__)  ,_sstd_key_at( 490 ,__VA_ARGS__)  ,_sstd_key_at( 491 ,__VA_ARGS__)  ,_sstd_key_at( 492 ,__VA_ARGS__)  ,_sstd_key_at( 493 ,__VA_ARGS__)  ,_sstd_key_at( 494 ,__VA_ARGS__)  ,_sstd_key_at( 495 ,__VA_ARGS__)  ,_sstd_key_at( 496 ,__VA_ARGS__)  ,_sstd_key_at( 497 ,__VA_ARGS__)  ,_sstd_key_at( 498 ,__VA_ARGS__)  ,_sstd_key_at( 499 ,__VA_ARGS__)  ,_sstd_key_at( 500 ,__VA_ARGS__)  ,_sstd_key_at( 501 ,__VA_ARGS__)  ,_sstd_key_at( 502 ,__VA_ARGS__)  ,_sstd_key_at( 503 ,__VA_ARGS__)  ,_sstd_key_at( 504 ,__VA_ARGS__)  ,_sstd_key_at( 505 ,__VA_ARGS__)  ,_sstd_key_at( 506 ,__VA_ARGS__)  ,_sstd_key_at( 507 ,__VA_ARGS__)  ,_sstd_key_at( 508 ,__VA_ARGS__)  ,_sstd_key_at( 509 ,__VA_ARGS__)  ,_sstd_key_at( 510 ,__VA_ARGS__)  ,_sstd_key_at( 511 ,__VA_ARGS__)  >::type 
#endif
