﻿//  Copyright John Maddock 2008.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

   static const boost::array<boost::array<typename table_type<T>::type, 2>, 100> expinti_data_long = {{
      {{ SC_(850.51361083984375), SC_(0.27809823533792637952061836944224670902e367) }},
      {{ SC_(1136.15478515625), SC_(0.2348005093803919554840423708437417479629e491) }},
      {{ SC_(1163.7506103515625), SC_(0.2213003663371766101124862788858798209669e503) }},
      {{ SC_(1177.1153564453125), SC_(0.1393972678294381321914138715599921955926e509) }},
      {{ SC_(1184.819580078125), SC_(0.3071287487721510514525001455932125917587e512) }},
      {{ SC_(1287.56982421875), SC_(0.1188602460855659524267859866086060607259e557) }},
      {{ SC_(1340.845458984375), SC_(0.1565775363947514543544059577542317926535e580) }},
      {{ SC_(1825.7115478515625), SC_(0.4317742008433835384506876651615126974963e790) }},
      {{ SC_(1830.026611328125), SC_(0.3222842941582302836955227140289123449271e792) }},
      {{ SC_(1960.14013671875), SC_(0.9682326984764871443713708725009118516667e848) }},
      {{ SC_(1987.625244140625), SC_(0.8252010696701409604448632584198026007861e860) }},
      {{ SC_(2121.929931640625), SC_(0.1644122120004322809189630355750827856571e919) }},
      {{ SC_(2129.468505859375), SC_(0.3078607683726664945534741803554577395453e922) }},
      {{ SC_(2140.980712890625), SC_(0.3059846959258757487477467065245238848267e927) }},
      {{ SC_(2230.63720703125), SC_(0.2542119875349999176355379625196504093816e966) }},
      {{ SC_(2298.31982421875), SC_(0.6114992506410978259391244796777268178912e995) }},
      {{ SC_(2374.6435546875), SC_(0.830188785884719427191192371811470577614e1028) }},
      {{ SC_(2464.39404296875), SC_(0.7606769935221277835214875514322852420595e1067) }},
      {{ SC_(2607.7314453125), SC_(0.1280208651710915937668281576410585595382e1130) }},
      {{ SC_(2636.01611328125), SC_(0.2434831958141217397564034109022725860803e1142) }},
      {{ SC_(2773.374755859375), SC_(0.1043520151961041658604037267493948608009e1202) }},
      {{ SC_(2789.313720703125), SC_(0.8673924117610746105433718703338830121224e1208) }},
      {{ SC_(3019.807861328125), SC_(0.1014040167380916647540036248296427121987e1309) }},
      {{ SC_(3037.9208984375), SC_(0.7410529098571197987076032731629101798719e1316) }},
      {{ SC_(3134.11962890625), SC_(0.4314033621612001130684487653920208910505e1358) }},
      {{ SC_(3724.306640625), SC_(0.7497114876830077572608496589486939616531e1614) }},
      {{ SC_(3740.94140625), SC_(0.1251252881668710692336811165448253472824e1622) }},
      {{ SC_(3936.630859375), SC_(0.1153573278500689879003545458843117005296e1707) }},
      {{ SC_(3988.202392578125), SC_(0.2841996613630984591213735017628358662044e1729) }},
      {{ SC_(4054.243896484375), SC_(0.1342609828695717510201743140807115713194e1758) }},
      {{ SC_(4142.7724609375), SC_(0.3681572481442059810190451103963992112454e1796) }},
      {{ SC_(4148.5703125), SC_(0.121171581000799833633456183949328398278e1799) }},
      {{ SC_(4615.2646484375), SC_(0.5246465971256288730180022026676777543742e2001) }},
      {{ SC_(4829.25732421875), SC_(0.4325309705481133900503845562540831591495e2094) }},
      {{ SC_(4941.91748046875), SC_(0.357836144515945182929963672150715372631e2143) }},
      {{ SC_(5010.6787109375), SC_(0.2572200946506254896455407953607460924114e2173) }},
      {{ SC_(5116.201171875), SC_(0.1694628673308089036903938764581354437254e2219) }},
      {{ SC_(5253.798828125), SC_(0.9450381302497917822730309088983075713142e2278) }},
      {{ SC_(5257.24560546875), SC_(0.2965383255217071801210759810882002854358e2280) }},
      {{ SC_(5433.140625), SC_(0.7047285278346101208658057139925849862554e2356) }},
      {{ SC_(5505.39013671875), SC_(0.1659005813598457669810325988575538660018e2388) }},
      {{ SC_(5636.36572265625), SC_(0.123483589653905750755240300669656546009e2445) }},
      {{ SC_(5813.45166015625), SC_(0.9674253782674757458616517516767150594778e2521) }},
      {{ SC_(5925.56689453125), SC_(0.465959154348727474260042419560482730271e2570) }},
      {{ SC_(5948.7275390625), SC_(0.5311210417035456841299141336297429192824e2580) }},
      {{ SC_(5971.912109375), SC_(0.6200616140526457518581489641316743841867e2590) }},
      {{ SC_(5980.62060546875), SC_(0.3748467021497618776363280710356423632891e2594) }},
      {{ SC_(6118.67822265625), SC_(0.3323548513925888198554192040808784242521e2654) }},
      {{ SC_(6575.06884765625), SC_(0.4992113296799401332170302610613651749985e2852) }},
      {{ SC_(6578.6494140625), SC_(0.1790887030753559149862073840512717626631e2854) }},
      {{ SC_(7477.7138671875), SC_(0.453063439997264160754767400139975001266e3244) }},
      {{ SC_(7555.90087890625), SC_(0.4053486713272468063037722021443381630624e3278) }},
      {{ SC_(7625.0654296875), SC_(0.4381811161168660111987981480837499404122e3308) }},
      {{ SC_(7721.84619140625), SC_(0.4650783679722625981733974952858145989039e3350) }},
      {{ SC_(7724.62158203125), SC_(0.7459451366176179637703427587587394395181e3351) }},
      {{ SC_(7807.67431640625), SC_(0.8657770283993666196881334661703905178512e3387) }},
      {{ SC_(7967.44287109375), SC_(0.2066376033881102222399296966624611161435e3457) }},
      {{ SC_(7995.15673828125), SC_(0.2237075980936927860568603957470382881289e3469) }},
      {{ SC_(8137.39013671875), SC_(0.1297781899952190216559462644235208641515e3531) }},
      {{ SC_(8255.8466796875), SC_(0.3564079826420461256934314917221024535487e3582) }},
      {{ SC_(8290.892578125), SC_(0.589315461709375088751076327530039211034e3597) }},
      {{ SC_(8464.859375), SC_(0.2061333287437003593390952585665220300663e3673) }},
      {{ SC_(8621.2353515625), SC_(0.1657376800782722410304770650822997699241e3741) }},
      {{ SC_(8647.478515625), SC_(0.4124415895621698868851529362785050121075e3752) }},
      {{ SC_(8769.4912109375), SC_(0.3969329427154640956668041611282529236515e3805) }},
      {{ SC_(8801.736328125), SC_(0.3990244136134911987900607765723496356083e3819) }},
      {{ SC_(8865.2001953125), SC_(0.1445061203725423928848837944828607819372e3847) }},
      {{ SC_(8883.857421875), SC_(0.1826853197788422299249942076987355766608e3855) }},
      {{ SC_(9165.708984375), SC_(0.4515605271244922649573310924321143987289e3977) }},
      {{ SC_(9184.3759765625), SC_(0.5765062048528042160801422542318948604069e3985) }},
      {{ SC_(9197.3115234375), SC_(0.238797240985925516325017189407703419842e3991) }},
      {{ SC_(9219.275390625), SC_(0.8237200206643906423722827693221290304098e4000) }},
      {{ SC_(9226.1259765625), SC_(0.7773715903123152522709440763956473274495e4003) }},
      {{ SC_(9227.998046875), SC_(0.5053244921662419600389850256151955782088e4004) }},
      {{ SC_(9250.9619140625), SC_(0.4737744487728344772209960864307761252156e4014) }},
      {{ SC_(9327.52734375), SC_(0.839334799085535932104716295994462739704e4047) }},
      {{ SC_(9403.482421875), SC_(0.8077630243130543392122877176716464625234e4080) }},
      {{ SC_(9479.298828125), SC_(0.6767729229089682203216741035877315937008e4113) }},
      {{ SC_(9495.71484375), SC_(0.9100734532106930249198078682510663631931e4120) }},
      {{ SC_(9617.6904296875), SC_(0.8449998576157010058160975375848278518588e4173) }},
      {{ SC_(9766.8056640625), SC_(0.4787377238207901984222005262457964596487e4238) }},
      {{ SC_(10012.8486328125), SC_(0.3344992068689187467671400212667671782847e4345) }},
      {{ SC_(10076.2275390625), SC_(0.11136885577784012567387295792753442916e4373) }},
      {{ SC_(10365.1630859375), SC_(0.3293047656065511164747161575530322956908e4498) }},
      {{ SC_(10445.2490234375), SC_(0.1973039455254220882950372775604517375325e4533) }},
      {{ SC_(10470.1669921875), SC_(0.1305681315488859113163146324068469579781e4544) }},
      {{ SC_(10524.4375), SC_(0.4819186831856610440931487751621965500502e4567) }},
      {{ SC_(10662.96875), SC_(0.6928694779347995167937115115212504365928e4627) }},
      {{ SC_(10834.3447265625), SC_(0.1825438577646410483210158166935577469757e4702) }},
      {{ SC_(10907.68359375), SC_(0.1285589751375311174300431256570906461288e4734) }},
      {{ SC_(10911.2724609375), SC_(0.4651411212288175929735371788790669615768e4735) }},
      {{ SC_(10932.240234375), SC_(0.5928423151111867954833915596799084326543e4744) }},
      {{ SC_(10989.22265625), SC_(0.3294826635257870726228138790579703502685e4769) }},
      {{ SC_(11018.8583984375), SC_(0.2439507354669304579499512829726839932215e4782) }},
      {{ SC_(11031.244140625), SC_(0.5832754259182122887134092147181083406225e4787) }},
      {{ SC_(11049.4599609375), SC_(0.474446561495313567373051850934536721701e4795) }},
      {{ SC_(11160.5185546875), SC_(0.8016374991446073482862383560024456346995e4843) }},
      {{ SC_(11284.826171875), SC_(0.7678551455742636373830825128178952778616e4897) }},
      {{ SC_(11297.36328125), SC_(0.2135966594384904628860134271820875984946e4903) }},
      {{ SC_(11322.6318359375), SC_(0.2007326162507306591356341202787380118764e4914) }}
   }};


