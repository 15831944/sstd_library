 template< auto A0 
,auto A1 ,auto A2 ,auto A3 ,auto A4 ,auto A5 ,auto A6 ,auto A7 ,auto A8 ,auto A9 ,auto A10 ,auto A11 ,auto A12  ,auto ... Args >  class string_constexpr_builder_helper< 13, A0
 , A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10  , A11  , A12  ,Args ... > {
public: 
using type = constexpr_string_literal< A0   , A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10  , A11  , A12 >;
};
