﻿//  (C) Copyright John Maddock 2006-7.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

   static const boost::array<boost::array<typename table_type<T>::type, 3>, 280> laguerre2 = {{
      {{ SC_(0.5e1), SC_(0.9754039764404296875e2), SC_(-0.56218428868911115998451316426215010600803852349048e8) }},
      {{ SC_(0.5e1), SC_(0.12698681640625e3), SC_(-0.2243354877625806499089339248835065869040287604245e9) }},
      {{ SC_(0.5e1), SC_(0.1354770050048828125e3), SC_(-0.31418973293934559300911242611564538290439848722478e9) }},
      {{ SC_(0.5e1), SC_(0.1883819732666015625e3), SC_(-0.17256344438562512861154328485542977773202418102338e10) }},
      {{ SC_(0.5e1), SC_(0.2210340576171875e3), SC_(-0.39170586692926680364193521563384606561329196831404e10) }},
      {{ SC_(0.5e1), SC_(0.27849822998046875e3), SC_(-0.12743797194803555297871516510157023166259117561797e11) }},
      {{ SC_(0.5e1), SC_(0.30816705322265625e3), SC_(-0.21330001890239721242857731991140245635183835676285e11) }},
      {{ SC_(0.5e1), SC_(0.5468814697265625e3), SC_(-0.38928352555423736374909603306210170085670252415611e12) }},
      {{ SC_(0.5e1), SC_(0.5472205810546875e3), SC_(-0.39050320967058708332723880470821630124002299400132e12) }},
      {{ SC_(0.5e1), SC_(0.6323592529296875e3), SC_(-0.8097387851220286833483200510030936982898650914701e12) }},
      {{ SC_(0.5e1), SC_(0.81472369384765625e3), SC_(-0.29004794312410106580901353153584987792805041014836e13) }},
      {{ SC_(0.5e1), SC_(0.835008544921875e3), SC_(-0.32824640180206380842810590985413965806061220575884e13) }},
      {{ SC_(0.5e1), SC_(0.90579193115234375e3), SC_(-0.49421323240476384503475902217971923134518824327159e13) }},
      {{ SC_(0.5e1), SC_(0.9133758544921875e3), SC_(-0.51537136874727263493269087352302138644536549927366e13) }},
      {{ SC_(0.5e1), SC_(0.9575068359375e3), SC_(-0.65333402285178696166233025823588675962128036189824e13) }},
      {{ SC_(0.5e1), SC_(0.96488848876953125e3), SC_(-0.67904577991104770306176706554532355404413293600378e13) }},
      {{ SC_(0.5e1), SC_(0.9676949462890625e3), SC_(-0.68903095684447650874743766361869788199054585412876e13) }},
      {{ SC_(0.5e1), SC_(0.9688677978515625e3), SC_(-0.69323852072435892067304941218115151610034557760898e13) }},
      {{ SC_(0.5e1), SC_(0.99288128662109375e3), SC_(-0.78400756116163888448805990221667549169323386803558e13) }},
      {{ SC_(0.5e1), SC_(0.9964613037109375e3), SC_(-0.79831715395647963750699081595768764433417262009011e13) }},
      {{ SC_(0.6e1), SC_(0.9754039764404296875e2), SC_(0.80820995722555766966204481326428921093819853380883e9) }},
      {{ SC_(0.6e1), SC_(0.12698681640625e3), SC_(0.43287285333593211699487383676400548034517465653989e10) }},
      {{ SC_(0.6e1), SC_(0.1354770050048828125e3), SC_(0.65078719322668723671436292885961437403753159577959e10) }},
      {{ SC_(0.6e1), SC_(0.1883819732666015625e3), SC_(0.50975971206548972048503974573840505796401940705308e11) }},
      {{ SC_(0.6e1), SC_(0.2210340576171875e3), SC_(0.13704228670315682904098855918609456694715553605731e12) }},
      {{ SC_(0.6e1), SC_(0.27849822998046875e3), SC_(0.56796012600833411397117536544899859778691289306697e12) }},
      {{ SC_(0.6e1), SC_(0.30816705322265625e3), SC_(0.10561318402049538938483073960821297722447423948919e13) }},
      {{ SC_(0.6e1), SC_(0.5468814697265625e3), SC_(0.34765288907987505446684019181571310232694381424255e14) }},
      {{ SC_(0.6e1), SC_(0.5472205810546875e3), SC_(0.34896286395332650547095052626160857783947143332365e14) }},
      {{ SC_(0.6e1), SC_(0.6323592529296875e3), SC_(0.83851035075753307874674729684024391015233495095035e14) }},
      {{ SC_(0.6e1), SC_(0.81472369384765625e3), SC_(0.38851567401648686934604173193933429726823924901636e15) }},
      {{ SC_(0.6e1), SC_(0.835008544921875e3), SC_(0.45077984162776358272899308358214843622672411937698e15) }},
      {{ SC_(0.6e1), SC_(0.90579193115234375e3), SC_(0.73700705849391831486587833923818658629022423687651e15) }},
      {{ SC_(0.6e1), SC_(0.9133758544921875e3), SC_(0.77507405395421988441046439866170936792437945158589e15) }},
      {{ SC_(0.6e1), SC_(0.9575068359375e3), SC_(0.10306131640131364207923517549718197693249532864712e16) }},
      {{ SC_(0.6e1), SC_(0.96488848876953125e3), SC_(0.10795269882491233868704393921117749304908016202882e16) }},
      {{ SC_(0.6e1), SC_(0.9676949462890625e3), SC_(0.10986241099950023947147288133858596641922819961585e16) }},
      {{ SC_(0.6e1), SC_(0.9688677978515625e3), SC_(0.11066879989104805588335103036958066630483588267248e16) }},
      {{ SC_(0.6e1), SC_(0.99288128662109375e3), SC_(0.12829707187512957309933510816037300428272415242332e16) }},
      {{ SC_(0.6e1), SC_(0.9964613037109375e3), SC_(0.13111507527148485594511524621819926397653608283432e16) }},
      {{ SC_(0.7e1), SC_(0.9754039764404296875e2), SC_(-0.97127257986443053526417273414388194974570607385935e10) }},
      {{ SC_(0.7e1), SC_(0.12698681640625e3), SC_(-0.70295995953992755265946027355243029063331213138355e11) }},
      {{ SC_(0.7e1), SC_(0.1354770050048828125e3), SC_(-0.11359707497453571901517561189586228142270903451764e12) }},
      {{ SC_(0.7e1), SC_(0.1883819732666015625e3), SC_(-0.12757018018175550435561074775586631022961625260251e13) }},
      {{ SC_(0.7e1), SC_(0.2210340576171875e3), SC_(-0.40694229451399857384340512241235666223436876850873e13) }},
      {{ SC_(0.7e1), SC_(0.27849822998046875e3), SC_(-0.21530849338789697137868260826250260284211997386438e14) }},
      {{ SC_(0.7e1), SC_(0.30816705322265625e3), SC_(-0.44515334725225153366608120310697334717448915933102e14) }},
      {{ SC_(0.7e1), SC_(0.5468814697265625e3), SC_(-0.26511725480730864342211918127699219873844104369464e16) }},
      {{ SC_(0.7e1), SC_(0.5472205810546875e3), SC_(-0.26628530536439102004691253957341772339263353080574e16) }},
      {{ SC_(0.7e1), SC_(0.6323592529296875e3), SC_(-0.74184365727412655859533662592614553371253178512618e16) }},
      {{ SC_(0.7e1), SC_(0.81472369384765625e3), SC_(-0.44494974059088898431029461327818954373425462460445e17) }},
      {{ SC_(0.7e1), SC_(0.835008544921875e3), SC_(-0.52932169558920439326767431099304484428916542881846e17) }},
      {{ SC_(0.7e1), SC_(0.90579193115234375e3), SC_(-0.93994900318821345331729187319793077343112028474933e17) }},
      {{ SC_(0.7e1), SC_(0.9133758544921875e3), SC_(-0.99689577334518532843192829626785299168262387676718e17) }},
      {{ SC_(0.7e1), SC_(0.9575068359375e3), SC_(-0.13905456836803030189577542899606637451372078172117e18) }},
      {{ SC_(0.7e1), SC_(0.96488848876953125e3), SC_(-0.14679265295479813112392016144737523708985227232103e18) }},
      {{ SC_(0.7e1), SC_(0.9676949462890625e3), SC_(-0.1498299348323053192424220347660666492880084886241e18) }},
      {{ SC_(0.7e1), SC_(0.9688677978515625e3), SC_(-0.1511151180165814270743545859553488460065643424192e18) }},
      {{ SC_(0.7e1), SC_(0.99288128662109375e3), SC_(-0.17958742259050562450977760208841036922467251612191e18) }},
      {{ SC_(0.7e1), SC_(0.9964613037109375e3), SC_(-0.18420258994246922874363794194214384956627167378336e18) }},
      {{ SC_(0.9e1), SC_(0.9754039764404296875e2), SC_(-0.88182421198196903206078231205307338249650868832064e12) }},
      {{ SC_(0.9e1), SC_(0.12698681640625e3), SC_(-0.11916795524742195589589499951943501492084977319524e14) }},
      {{ SC_(0.9e1), SC_(0.1354770050048828125e3), SC_(-0.22344296397638552568674348465205379613306362764566e14) }},
      {{ SC_(0.9e1), SC_(0.1883819732666015625e3), SC_(-0.52450137180856257840726851581544345839939827576715e15) }},
      {{ SC_(0.9e1), SC_(0.2210340576171875e3), SC_(-0.23696400879105564578477838259302061169946747558952e16) }},
      {{ SC_(0.9e1), SC_(0.27849822998046875e3), SC_(-0.2057154069965741250232756687863533313808633945305e17) }},
      {{ SC_(0.9e1), SC_(0.30816705322265625e3), SC_(-0.52706299238279057416545711578165684905744102859115e17) }},
      {{ SC_(0.9e1), SC_(0.5468814697265625e3), SC_(-0.10373504112979138086350224207396056466588729804516e20) }},
      {{ SC_(0.9e1), SC_(0.5472205810546875e3), SC_(-0.10432528153473136570046121526504633952860788360435e20) }},
      {{ SC_(0.9e1), SC_(0.6323592529296875e3), SC_(-0.39130711594017381807257779551743819698560088375668e20) }},
      {{ SC_(0.9e1), SC_(0.81472369384765625e3), SC_(-0.39417960379424891896054061064677368280593070059738e21) }},
      {{ SC_(0.9e1), SC_(0.835008544921875e3), SC_(-0.49304936215932770879646299983700202838606715074253e21) }},
      {{ SC_(0.9e1), SC_(0.90579193115234375e3), SC_(-0.10334424643188761615583739852552783075006729859411e22) }},
      {{ SC_(0.9e1), SC_(0.9133758544921875e3), SC_(-0.11148197370742169335891238953970561388157054787912e22) }},
      {{ SC_(0.9e1), SC_(0.9575068359375e3), SC_(-0.17117643007530823467479808245288438345428761729566e22) }},
      {{ SC_(0.9e1), SC_(0.96488848876953125e3), SC_(-0.18354699865344307677650783008677515871579118218563e22) }},
      {{ SC_(0.9e1), SC_(0.9676949462890625e3), SC_(-0.18845473402555581720266649838772564615998761460957e22) }},
      {{ SC_(0.9e1), SC_(0.9688677978515625e3), SC_(-0.19054005396362814451214549815853296627845049820834e22) }},
      {{ SC_(0.9e1), SC_(0.99288128662109375e3), SC_(-0.2379990415149925129095832370169236951708289834945e22) }},
      {{ SC_(0.9e1), SC_(0.9964613037109375e3), SC_(-0.2459080438944659678243208011185696524084223075751e22) }},
      {{ SC_(0.1e2), SC_(0.9754039764404296875e2), SC_(0.68363285133790726530343716793230261010875353582126e13) }},
      {{ SC_(0.1e2), SC_(0.12698681640625e3), SC_(0.12780346463262387447059318050624889749180569846779e15) }},
      {{ SC_(0.1e2), SC_(0.1354770050048828125e3), SC_(0.25872514080382692007093467972049926364267470684414e15) }},
      {{ SC_(0.1e2), SC_(0.1883819732666015625e3), SC_(0.88592647116085797035522910089956721973984668164933e16) }},
      {{ SC_(0.1e2), SC_(0.2210340576171875e3), SC_(0.47780583657418526717172656140732828044696456184005e17) }},
      {{ SC_(0.1e2), SC_(0.27849822998046875e3), SC_(0.5331900363941173927045807539300156181950112131739e18) }},
      {{ SC_(0.1e2), SC_(0.30816705322265625e3), SC_(0.1522625182085023713301500547784155501632626718952e19) }},
      {{ SC_(0.1e2), SC_(0.5468814697265625e3), SC_(0.54743944979053298043671516089410722749901760176246e21) }},
      {{ SC_(0.1e2), SC_(0.5472205810546875e3), SC_(0.55090819795558138013756209863788327369928434403532e21) }},
      {{ SC_(0.1e2), SC_(0.6323592529296875e3), SC_(0.23996032369722453090472613853380539435510387147265e22) }},
      {{ SC_(0.1e2), SC_(0.81472369384765625e3), SC_(0.3136180217844875856210532455123015078868701049189e23) }},
      {{ SC_(0.1e2), SC_(0.835008544921875e3), SC_(0.40228366570492581887821535861784155838787837068917e23) }},
      {{ SC_(0.1e2), SC_(0.90579193115234375e3), SC_(0.91635424833598371783927550180351600428358564325103e23) }},
      {{ SC_(0.1e2), SC_(0.9133758544921875e3), SC_(0.99696710750634214960945727157571811141128625200737e23) }},
      {{ SC_(0.1e2), SC_(0.9575068359375e3), SC_(0.16063550635202090204108065161018414051528464203492e24) }},
      {{ SC_(0.1e2), SC_(0.96488848876953125e3), SC_(0.17359930740134722080034670472759394163212119095913e24) }},
      {{ SC_(0.1e2), SC_(0.9676949462890625e3), SC_(0.17876999613951749665069145752320997385967469183553e24) }},
      {{ SC_(0.1e2), SC_(0.9688677978515625e3), SC_(0.18097164614992113510626725680969708377447448480682e24) }},
      {{ SC_(0.1e2), SC_(0.99288128662109375e3), SC_(0.23176305706781278086716530835422934581699500133195e24) }},
      {{ SC_(0.1e2), SC_(0.9964613037109375e3), SC_(0.24034525959278928207216174690071010414578307080004e24) }},
      {{ SC_(0.12e2), SC_(0.9754039764404296875e2), SC_(0.28423596453596289989288243804391945134145720558303e15) }},
      {{ SC_(0.12e2), SC_(0.12698681640625e3), SC_(0.10459814166195030538123822665486701112739697771504e17) }},
      {{ SC_(0.12e2), SC_(0.1354770050048828125e3), SC_(0.24809961434471699525764703789755549215916991317009e17) }},
      {{ SC_(0.12e2), SC_(0.1883819732666015625e3), SC_(0.18432001419367650072987948319941023048367873500947e19) }},
      {{ SC_(0.12e2), SC_(0.2210340576171875e3), SC_(0.1425973246788753700961735353907762908357118808801e20) }},
      {{ SC_(0.12e2), SC_(0.27849822998046875e3), SC_(0.2648612039362625663502673525170355605919867648175e21) }},
      {{ SC_(0.12e2), SC_(0.30816705322265625e3), SC_(0.94207669859466343227329712354536538487224976251934e21) }},
      {{ SC_(0.12e2), SC_(0.5468814697265625e3), SC_(0.11416571288332122735760393265732692757218749094333e25) }},
      {{ SC_(0.12e2), SC_(0.5472205810546875e3), SC_(0.11503772311632575693339455966945777225801334633802e25) }},
      {{ SC_(0.12e2), SC_(0.6323592529296875e3), SC_(0.67682817776609426691165241302499154756436610551448e25) }},
      {{ SC_(0.12e2), SC_(0.81472369384765625e3), SC_(0.14925113607158546323278613008648061457814853288569e27) }},
      {{ SC_(0.12e2), SC_(0.835008544921875e3), SC_(0.20137386892159007353644931592676274228203562748065e27) }},
      {{ SC_(0.12e2), SC_(0.90579193115234375e3), SC_(0.5420836690576459643271287711084458171666413772841e27) }},
      {{ SC_(0.12e2), SC_(0.9133758544921875e3), SC_(0.59993957244253616872158941998241312745401619591825e27) }},
      {{ SC_(0.12e2), SC_(0.9575068359375e3), SC_(0.10647596238911981020997681650094944029068747024397e28) }},
      {{ SC_(0.12e2), SC_(0.96488848876953125e3), SC_(0.11689245133960734996588218891178658140879248121018e28) }},
      {{ SC_(0.12e2), SC_(0.9676949462890625e3), SC_(0.1210919349676828488255310851429670495905368349189e28) }},
      {{ SC_(0.12e2), SC_(0.9688677978515625e3), SC_(0.12288756773958775796104364572786513910596933472569e28) }},
      {{ SC_(0.12e2), SC_(0.99288128662109375e3), SC_(0.16546282318562297815258073400590724827059252937711e28) }},
      {{ SC_(0.12e2), SC_(0.9964613037109375e3), SC_(0.17285799188257724376176157543505720262452819750787e28) }},
      {{ SC_(0.13e2), SC_(0.9754039764404296875e2), SC_(-0.15428758327644125855292818843401569330741211168799e16) }},
      {{ SC_(0.13e2), SC_(0.12698681640625e3), SC_(-0.80932019891477222056421384256018993299108719527302e17) }},
      {{ SC_(0.13e2), SC_(0.1354770050048828125e3), SC_(-0.20837410443315613138060768891043617064680947230019e18) }},
      {{ SC_(0.13e2), SC_(0.1883819732666015625e3), SC_(-0.23041054581252941723867939936368964100938528845819e20) }},
      {{ SC_(0.13e2), SC_(0.2210340576171875e3), SC_(-0.21423018746076790532404088387932487576331298937838e21) }},
      {{ SC_(0.13e2), SC_(0.27849822998046875e3), SC_(-0.51532533774072113882814592946620765040457802277968e22) }},
      {{ SC_(0.13e2), SC_(0.30816705322265625e3), SC_(-0.20483743080238166781000622328713314260809968894106e23) }},
      {{ SC_(0.13e2), SC_(0.5468814697265625e3), SC_(-0.45807365658624583832010377136032803302289663432229e26) }},
      {{ SC_(0.13e2), SC_(0.5472205810546875e3), SC_(-0.46187271245529335025545254036134744857983676852153e26) }},
      {{ SC_(0.13e2), SC_(0.6323592529296875e3), SC_(-0.31609066199338067621059954633340634981067166015523e27) }},
      {{ SC_(0.13e2), SC_(0.81472369384765625e3), SC_(-0.90646159399960206374430498227033140094018657322162e28) }},
      {{ SC_(0.13e2), SC_(0.835008544921875e3), SC_(-0.12544525904974860594398806285643930469586501530176e29) }},
      {{ SC_(0.13e2), SC_(0.90579193115234375e3), SC_(-0.36721114150131761392182317349435587031972338255613e29) }},
      {{ SC_(0.13e2), SC_(0.9133758544921875e3), SC_(-0.40990368279471938330945117709437735030275122009372e29) }},
      {{ SC_(0.13e2), SC_(0.9575068359375e3), SC_(-0.76363964177698049737267049485284900489556590512731e29) }},
      {{ SC_(0.13e2), SC_(0.96488848876953125e3), SC_(-0.84498458446138963220029970565385666164418294081343e29) }},
      {{ SC_(0.13e2), SC_(0.9676949462890625e3), SC_(-0.87795611207460053386552725647471806319942125987039e29) }},
      {{ SC_(0.13e2), SC_(0.9688677978515625e3), SC_(-0.8920838990438100428530933894339887359239837726742e29) }},
      {{ SC_(0.13e2), SC_(0.99288128662109375e3), SC_(-0.12317215421451917683521586907330444625122803485384e30) }},
      {{ SC_(0.13e2), SC_(0.9964613037109375e3), SC_(-0.12915328980215273183944018711642638080541797445587e30) }},
      {{ SC_(0.22e2), SC_(0.9754039764404296875e2), SC_(0.53519155913211797117581773427472182753318968475881e20) }},
      {{ SC_(0.22e2), SC_(0.12698681640625e3), SC_(0.1482457856077086365579374192841961715732300978721e24) }},
      {{ SC_(0.22e2), SC_(0.1354770050048828125e3), SC_(0.89811862298211814442148491712564277702535951184385e24) }},
      {{ SC_(0.22e2), SC_(0.1883819732666015625e3), SC_(0.53105205911452770051774832885086163468318926564375e28) }},
      {{ SC_(0.22e2), SC_(0.2210340576171875e3), SC_(0.29181385527902060628744587044238065323351755162445e30) }},
      {{ SC_(0.22e2), SC_(0.27849822998046875e3), SC_(0.81926383490939917849013990628644623870335123644678e32) }},
      {{ SC_(0.22e2), SC_(0.30816705322265625e3), SC_(0.92559256235836508755914064074846859174102223189673e33) }},
      {{ SC_(0.22e2), SC_(0.5468814697265625e3), SC_(0.60582355648139314032220922737227351534361291594301e39) }},
      {{ SC_(0.22e2), SC_(0.5472205810546875e3), SC_(0.61450841386618840767372822554085603258088547262603e39) }},
      {{ SC_(0.22e2), SC_(0.6323592529296875e3), SC_(0.16828697247343434191793544661262546124370931417734e41) }},
      {{ SC_(0.22e2), SC_(0.81472369384765625e3), SC_(0.53252364000408391115685655166260738513117912209307e43) }},
      {{ SC_(0.22e2), SC_(0.835008544921875e3), SC_(0.92881368091496514903641566811539878316737606628203e43) }},
      {{ SC_(0.22e2), SC_(0.90579193115234375e3), SC_(0.58353032082389612678363416640153420485594909764931e44) }},
      {{ SC_(0.22e2), SC_(0.9133758544921875e3), SC_(0.70428883480642630449395417614259444733071066152224e44) }},
      {{ SC_(0.22e2), SC_(0.9575068359375e3), SC_(0.20403604900694297028065932589821789954408762498582e45) }},
      {{ SC_(0.22e2), SC_(0.96488848876953125e3), SC_(0.24257231813723197693329702291105633653538223754681e45) }},
      {{ SC_(0.22e2), SC_(0.9676949462890625e3), SC_(0.25897178141402988728665269659702809950051225843733e45) }},
      {{ SC_(0.22e2), SC_(0.9688677978515625e3), SC_(0.26613428214690454856359092251155501252760949702349e45) }},
      {{ SC_(0.22e2), SC_(0.99288128662109375e3), SC_(0.46186282958538147848573463412585781275986740408896e45) }},
      {{ SC_(0.22e2), SC_(0.9964613037109375e3), SC_(0.50083750837345646151818682810006338938882917955936e45) }},
      {{ SC_(0.26e2), SC_(0.9754039764404296875e2), SC_(0.21972677691719817441756091279246498916850254461527e21) }},
      {{ SC_(0.26e2), SC_(0.12698681640625e3), SC_(0.1075388630949279748826454068162739903189328481612e26) }},
      {{ SC_(0.26e2), SC_(0.1354770050048828125e3), SC_(0.10649057118439433153896298751085699481345412933801e27) }},
      {{ SC_(0.26e2), SC_(0.1883819732666015625e3), SC_(0.5116947616838569524143836973058866982145398777318e31) }},
      {{ SC_(0.26e2), SC_(0.2210340576171875e3), SC_(0.67598194000593044124785906843654997129153545590891e33) }},
      {{ SC_(0.26e2), SC_(0.27849822998046875e3), SC_(0.61788821894450276203672680235188870492927609213655e36) }},
      {{ SC_(0.26e2), SC_(0.30816705322265625e3), SC_(0.1143466221863025445538605244032140245989208384596e38) }},
      {{ SC_(0.26e2), SC_(0.5468814697265625e3), SC_(0.10365782377701183452195461556076353497800893592323e45) }},
      {{ SC_(0.26e2), SC_(0.5472205810546875e3), SC_(0.10543127968944428085136728714429047403339769641033e45) }},
      {{ SC_(0.26e2), SC_(0.6323592529296875e3), SC_(0.54336316553928368949063555184249670518669259521127e46) }},
      {{ SC_(0.26e2), SC_(0.81472369384765625e3), SC_(0.51097552617218427263241448611405994401811535704536e49) }},
      {{ SC_(0.26e2), SC_(0.835008544921875e3), SC_(0.98954520453823509774054797214466944211629878869384e49) }},
      {{ SC_(0.26e2), SC_(0.90579193115234375e3), SC_(0.87786375743747677334359888017430029312432056322196e50) }},
      {{ SC_(0.26e2), SC_(0.9133758544921875e3), SC_(0.10975609743646233178198950358966597197707924620818e51) }},
      {{ SC_(0.26e2), SC_(0.9575068359375e3), SC_(0.38807135479289092313349072980539966631345258500198e51) }},
      {{ SC_(0.26e2), SC_(0.96488848876953125e3), SC_(0.47654821142237731628816607894656922038832987256136e51) }},
      {{ SC_(0.26e2), SC_(0.9676949462890625e3), SC_(0.51503194237863964904639112627180500133770486086125e51) }},
      {{ SC_(0.26e2), SC_(0.9688677978515625e3), SC_(0.53198500654007856666562730301281355378772116339286e51) }},
      {{ SC_(0.26e2), SC_(0.99288128662109375e3), SC_(0.10235016527486692862890189415524722222034128311139e52) }},
      {{ SC_(0.26e2), SC_(0.9964613037109375e3), SC_(0.11268082142512355561240466068867830761377375700468e52) }},
      {{ SC_(0.32e2), SC_(0.9754039764404296875e2), SC_(0.57896844151857557407003122100491148696303115075994e20) }},
      {{ SC_(0.32e2), SC_(0.12698681640625e3), SC_(0.42245682831545366496930901995710141383069638790405e27) }},
      {{ SC_(0.32e2), SC_(0.1354770050048828125e3), SC_(0.12500869474828256329426453946772458815922358559551e29) }},
      {{ SC_(0.32e2), SC_(0.1883819732666015625e3), SC_(0.28266779160071220855863136752236809118289513550655e35) }},
      {{ SC_(0.32e2), SC_(0.2210340576171875e3), SC_(0.16043258633437377313296386512455676335765088879499e38) }},
      {{ SC_(0.32e2), SC_(0.27849822998046875e3), SC_(0.98152083075443552200456383499687746658509404557554e41) }},
      {{ SC_(0.32e2), SC_(0.30816705322265625e3), SC_(0.39660303068870304789061389710467952730805922359184e43) }},
      {{ SC_(0.32e2), SC_(0.5468814697265625e3), SC_(0.2124691778655363299602608193872213697408649234399e52) }},
      {{ SC_(0.32e2), SC_(0.5472205810546875e3), SC_(0.21701146117737990401627817320898898731158045140974e52) }},
      {{ SC_(0.32e2), SC_(0.6323592529296875e3), SC_(0.29453956822267682637622660585710995711330784866261e54) }},
      {{ SC_(0.32e2), SC_(0.81472369384765625e3), SC_(0.14579187010342463619209867543395472012389261100613e58) }},
      {{ SC_(0.32e2), SC_(0.835008544921875e3), SC_(0.33104915961295333458609667123641141490590693664242e58) }},
      {{ SC_(0.32e2), SC_(0.90579193115234375e3), SC_(0.49617254391613681021336977691940022261460402301085e59) }},
      {{ SC_(0.32e2), SC_(0.9133758544921875e3), SC_(0.65447509655180124047279400990868215055245034097822e59) }},
      {{ SC_(0.32e2), SC_(0.9575068359375e3), SC_(0.31314186002835766887651202030265122705420348145384e60) }},
      {{ SC_(0.32e2), SC_(0.96488848876953125e3), SC_(0.40390183129399277888276794404622531827627609452775e60) }},
      {{ SC_(0.32e2), SC_(0.9676949462890625e3), SC_(0.44470349220352623223005295792036557179541953880227e60) }},
      {{ SC_(0.32e2), SC_(0.9688677978515625e3), SC_(0.46291347880797126364720392445817548485904681626203e60) }},
      {{ SC_(0.32e2), SC_(0.99288128662109375e3), SC_(0.10414215853249607927566783846023113314868365327492e61) }},
      {{ SC_(0.32e2), SC_(0.9964613037109375e3), SC_(0.11731839293063017507522289233426225751615807834469e61) }},
      {{ SC_(0.33e2), SC_(0.9754039764404296875e2), SC_(-0.15519766552964914960282162902087252393890944756729e21) }},
      {{ SC_(0.33e2), SC_(0.12698681640625e3), SC_(-0.49834394329409786429107636406724247060325054488444e27) }},
      {{ SC_(0.33e2), SC_(0.1354770050048828125e3), SC_(-0.19840581047253598115611184022145906036118542457808e29) }},
      {{ SC_(0.33e2), SC_(0.1883819732666015625e3), SC_(-0.98212428153399951310107146404282928611923578181199e35) }},
      {{ SC_(0.33e2), SC_(0.2210340576171875e3), SC_(-0.72578044049144687694845377262857641629094641588691e38) }},
      {{ SC_(0.33e2), SC_(0.27849822998046875e3), SC_(-0.62057397100619303564513894784492557621908539158042e42) }},
      {{ SC_(0.33e2), SC_(0.30816705322265625e3), SC_(-0.28714296782385167119124999018599500804762523101335e44) }},
      {{ SC_(0.33e2), SC_(0.5468814697265625e3), SC_(-0.30888931981090919336348667046948287489524269522361e53) }},
      {{ SC_(0.33e2), SC_(0.5472205810546875e3), SC_(-0.31571691597216716720754649436373448511713945451381e53) }},
      {{ SC_(0.33e2), SC_(0.6323592529296875e3), SC_(-0.50478315840421718669131419020872977517323737909924e55) }},
      {{ SC_(0.33e2), SC_(0.81472369384765625e3), SC_(-0.33062025262205293767486203308022299641518265442287e59) }},
      {{ SC_(0.33e2), SC_(0.835008544921875e3), SC_(-0.77112383731383286471230156867910260520520657245124e59) }},
      {{ SC_(0.33e2), SC_(0.90579193115234375e3), SC_(-0.1262346064599467935961005524047195599692654321956e61) }},
      {{ SC_(0.33e2), SC_(0.9133758544921875e3), SC_(-0.16801567279045565630405655696613192336457136904877e61) }},
      {{ SC_(0.33e2), SC_(0.9575068359375e3), SC_(-0.84582529186776869237021206078881700754491798000552e61) }},
      {{ SC_(0.33e2), SC_(0.96488848876953125e3), SC_(-0.11000226620410340743835989544374720411357868296468e62) }},
      {{ SC_(0.33e2), SC_(0.9676949462890625e3), SC_(-0.12149322908840894133499880791452022966588461024746e62) }},
      {{ SC_(0.33e2), SC_(0.9688677978515625e3), SC_(-0.12663293722507282266407117288015925037770799060973e62) }},
      {{ SC_(0.33e2), SC_(0.99288128662109375e3), SC_(-0.29247499878319565468778047006263649127299274582216e62) }},
      {{ SC_(0.33e2), SC_(0.9964613037109375e3), SC_(-0.33075364818279888462182974219279083273759877224615e62) }},
      {{ SC_(0.36e2), SC_(0.9754039764404296875e2), SC_(-0.14202381258875603292784398243371786895083677644968e21) }},
      {{ SC_(0.36e2), SC_(0.12698681640625e3), SC_(-0.99689260408784512857796674097683890787134923850651e23) }},
      {{ SC_(0.36e2), SC_(0.1354770050048828125e3), SC_(0.33085802053384704162061389949004801316875589574167e29) }},
      {{ SC_(0.36e2), SC_(0.1883819732666015625e3), SC_(0.29691002837109064218075098689453177656242661416649e37) }},
      {{ SC_(0.36e2), SC_(0.2210340576171875e3), SC_(0.50722869577926074483465513588442579657337298353026e40) }},
      {{ SC_(0.36e2), SC_(0.27849822998046875e3), SC_(0.12276018084343264808614960453898425578975135870535e45) }},
      {{ SC_(0.36e2), SC_(0.30816705322265625e3), SC_(0.86176792520194608969749051518980054897501919421191e46) }},
      {{ SC_(0.36e2), SC_(0.5468814697265625e3), SC_(0.77496906300517296899212867022166471009005365376408e56) }},
      {{ SC_(0.36e2), SC_(0.5472205810546875e3), SC_(0.79380346709534996703125888877181202810222361959297e56) }},
      {{ SC_(0.36e2), SC_(0.6323592529296875e3), SC_(0.20837628323063930783612574671644907853428390635937e59) }},
      {{ SC_(0.36e2), SC_(0.81472369384765625e3), SC_(0.31805284832302734783735872178451062267986916005535e63) }},
      {{ SC_(0.36e2), SC_(0.835008544921875e3), SC_(0.80427224577995045297081384061933456722295034711368e63) }},
      {{ SC_(0.36e2), SC_(0.90579193115234375e3), SC_(0.17180125938368536870586199334103942944296763636498e65) }},
      {{ SC_(0.36e2), SC_(0.9133758544921875e3), SC_(0.2349585543781729049082862094571853647181110727758e65) }},
      {{ SC_(0.36e2), SC_(0.9575068359375e3), SC_(0.13788032216346989091599957999852901194859847097388e66) }},
      {{ SC_(0.36e2), SC_(0.96488848876953125e3), SC_(0.18383754088256510557951005527578044897458936835611e66) }},
      {{ SC_(0.36e2), SC_(0.9676949462890625e3), SC_(0.20496108373672385020966386552222912655862108987654e66) }},
      {{ SC_(0.36e2), SC_(0.9688677978515625e3), SC_(0.21447176171446511024838576925006696393416059852805e66) }},
      {{ SC_(0.36e2), SC_(0.99288128662109375e3), SC_(0.53619191227443818889184097649341805455543103147757e66) }},
      {{ SC_(0.36e2), SC_(0.9964613037109375e3), SC_(0.6134634193224111642857607073780448563124536964454e66) }},
      {{ SC_(0.38e2), SC_(0.9754039764404296875e2), SC_(0.13026109621262939918139850088931337407072881569374e21) }},
      {{ SC_(0.38e2), SC_(0.12698681640625e3), SC_(-0.39045802697684580087249595226480504736900650572604e27) }},
      {{ SC_(0.38e2), SC_(0.1354770050048828125e3), SC_(0.4703084156408515882792903403585270483597230661564e28) }},
      {{ SC_(0.38e2), SC_(0.1883819732666015625e3), SC_(0.21811950666425589665298269088166544127028329061958e38) }},
      {{ SC_(0.38e2), SC_(0.2210340576171875e3), SC_(0.68226335876612312689262066243026383595759661918497e41) }},
      {{ SC_(0.38e2), SC_(0.27849822998046875e3), SC_(0.3417431296914681619225852746415756851618849310483e46) }},
      {{ SC_(0.38e2), SC_(0.30816705322265625e3), SC_(0.31970819524145633109548465679514234447503951190819e48) }},
      {{ SC_(0.38e2), SC_(0.5468814697265625e3), SC_(0.12178742579145686663348414006307088453127654992376e59) }},
      {{ SC_(0.38e2), SC_(0.5472205810546875e3), SC_(0.12492841620300639426815182320836485753685517201536e59) }},
      {{ SC_(0.38e2), SC_(0.6323592529296875e3), SC_(0.45810661530573839216333825165973798523285084973924e61) }},
      {{ SC_(0.38e2), SC_(0.81472369384765625e3), SC_(0.12351347140304796554466586331231292139128275112892e66) }},
      {{ SC_(0.38e2), SC_(0.835008544921875e3), SC_(0.32975853153845151581573454625890910497305801446349e66) }},
      {{ SC_(0.38e2), SC_(0.90579193115234375e3), SC_(0.84216312274962467518837779101216307869158288654706e67) }},
      {{ SC_(0.38e2), SC_(0.9133758544921875e3), SC_(0.11729374185740406136241147249355309364674121773484e68) }},
      {{ SC_(0.38e2), SC_(0.9575068359375e3), SC_(0.76287452793236059887210998415733522854114359820263e68) }},
      {{ SC_(0.38e2), SC_(0.96488848876953125e3), SC_(0.10342759141411866835170522110986503338234205828331e69) }},
      {{ SC_(0.38e2), SC_(0.9676949462890625e3), SC_(0.11604186211493955868813819686880547173842867350967e69) }},
      {{ SC_(0.38e2), SC_(0.9688677978515625e3), SC_(0.12174646477307642518592858476271949696633470067733e69) }},
      {{ SC_(0.38e2), SC_(0.99288128662109375e3), SC_(0.32098315809650975303906367704092470560267558301581e69) }},
      {{ SC_(0.38e2), SC_(0.9964613037109375e3), SC_(0.37011679718261969297940214190611219199030995011675e69) }},
      {{ SC_(0.39e2), SC_(0.9754039764404296875e2), SC_(-0.81788056310459660065120382039447835033044197049489e20) }},
      {{ SC_(0.39e2), SC_(0.12698681640625e3), SC_(0.22229715039776080683928576767759683825519547792559e27) }},
      {{ SC_(0.39e2), SC_(0.1354770050048828125e3), SC_(0.15550461280029801190156888344119462891700106953436e29) }},
      {{ SC_(0.39e2), SC_(0.1883819732666015625e3), SC_(-0.54226895058411233344275595074274527247091920347531e38) }},
      {{ SC_(0.39e2), SC_(0.2210340576171875e3), SC_(-0.23342183174200163814210714804874246930233709812346e42) }},
      {{ SC_(0.39e2), SC_(0.27849822998046875e3), SC_(-0.17013038203469478431364477259901167967979013129897e47) }},
      {{ SC_(0.39e2), SC_(0.30816705322265625e3), SC_(-0.18429253515276943444879261921619357066598024943888e49) }},
      {{ SC_(0.39e2), SC_(0.5468814697265625e3), SC_(-0.14577093593047894021012074885872239431277128765197e60) }},
      {{ SC_(0.39e2), SC_(0.5472205810546875e3), SC_(-0.14963982369811780116397608759812127691336981298577e60) }},
      {{ SC_(0.39e2), SC_(0.6323592529296875e3), SC_(-0.6492862403071900096406830281442380096038500168606e62) }},
      {{ SC_(0.39e2), SC_(0.81472369384765625e3), SC_(-0.23301820931113238390488179765094297019115309966495e67) }},
      {{ SC_(0.39e2), SC_(0.835008544921875e3), SC_(-0.6393122118320767120277111175042508309950280050084e67) }},
      {{ SC_(0.39e2), SC_(0.90579193115234375e3), SC_(-0.1785926484809201389439108598459489796533771170743e69) }},
      {{ SC_(0.39e2), SC_(0.9133758544921875e3), SC_(-0.25102368049271316850934544583200188325859894245069e69) }},
      {{ SC_(0.39e2), SC_(0.9575068359375e3), SC_(-0.17191430467481203804500407886563167282958450012617e70) }},
      {{ SC_(0.39e2), SC_(0.96488848876953125e3), SC_(-0.2350360204862166230883463530178770075607651772555e70) }},
      {{ SC_(0.39e2), SC_(0.9676949462890625e3), SC_(-0.26453813089044823183666856904573749479668606778886e70) }},
      {{ SC_(0.39e2), SC_(0.9688677978515625e3), SC_(-0.27790958611107454497958236687689216620181150284596e70) }},
      {{ SC_(0.39e2), SC_(0.99288128662109375e3), SC_(-0.75250430660256030378942490914723092683335523198301e70) }},
      {{ SC_(0.39e2), SC_(0.9964613037109375e3), SC_(-0.87109521955089946525219892186343098358449543636311e70) }}
   }};


