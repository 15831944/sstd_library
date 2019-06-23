﻿//  (C) Copyright John Maddock 2006-7.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

   static const boost::array<boost::array<typename table_type<T>::type, 4>, 160> legendre_p_large = {{
      {{ SC_(29.0), SC_(-0.74602639675140380859375), SC_(0.050915219643735786802064817454102557266509665552523), SC_(-0.27118035040452065163236941090242943684321195237749) }},
      {{ SC_(29.0), SC_(-0.72904598712921142578125), SC_(0.15209960929167220423613043592541930303920942697128), SC_(-0.1438359066051312703697159687668902900032679225431) }},
      {{ SC_(29.0), SC_(-0.5579319000244140625), SC_(0.15849246733249484229246386045081847903407720368835), SC_(-0.046562152771403674797644638451970346262085750814402) }},
      {{ SC_(29.0), SC_(-0.38366591930389404296875), SC_(0.12421123432704035296982084866318407821031736589989), SC_(-0.13993608234219292039527623183264127314107515942999) }},
      {{ SC_(29.0), SC_(0.264718532562255859375), SC_(0.14939214703729469665461134129487953904270632801499), SC_(0.011880798886655750194841085329195617037793542295307) }},
      {{ SC_(29.0), SC_(0.62944734096527099609375), SC_(0.15752641351603055527713997332857496041323176430518), SC_(-0.085333543185746265108134728242042619782666873361817) }},
      {{ SC_(29.0), SC_(0.67001712322235107421875), SC_(0.054837169775284662482177068305626352949947763721645), SC_(0.25355488589896471253311476119270056443895635234837) }},
      {{ SC_(29.0), SC_(0.81158387660980224609375), SC_(0.063381360227496634467950288363046198618583970049264), SC_(0.28493842219370104406874711812243725560916796813782) }},
      {{ SC_(29.0), SC_(0.826751708984375), SC_(-0.08420018636937566660354955907203801287585967235842), SC_(0.27769559592859630765679556893873497642068025145103) }},
      {{ SC_(29.0), SC_(0.93773555755615234375), SC_(-0.24176816577505910452921016056528287088649954762181), SC_(0.094296671036158090707906492415425184420130303729612) }},
      {{ SC_(32.0), SC_(-0.74602639675140380859375), SC_(-0.10624862108385367062544557604098705758947684718283), SC_(-0.21143967375447832725357384431573889445833865564692) }},
      {{ SC_(32.0), SC_(-0.72904598712921142578125), SC_(0.025162565093345926014241859993355739041989277225088), SC_(-0.26274148479323222549160374105375114037174210402628) }},
      {{ SC_(32.0), SC_(-0.5579319000244140625), SC_(0.14211456817063838568644446010057604214542220046016), SC_(-0.09163254161603810457705450004999666401809984055068) }},
      {{ SC_(32.0), SC_(-0.38366591930389404296875), SC_(0.14171288019304087574298677776314705938680717437038), SC_(-0.052711866447932948820821929976771090258669811818703) }},
      {{ SC_(32.0), SC_(0.264718532562255859375), SC_(-0.10746376970464863575465113222711354062288152228845), SC_(0.14703447108655800801097998317667773187484429086529) }},
      {{ SC_(32.0), SC_(0.62944734096527099609375), SC_(-0.15721886386953844900014008976876572130375292635363), SC_(-0.03463115417113285817814346783115703627607698101613) }},
      {{ SC_(32.0), SC_(0.67001712322235107421875), SC_(0.048628774250235041116639532793364743422360425715375), SC_(-0.24343097490553436355382554969125452470269482841518) }},
      {{ SC_(32.0), SC_(0.81158387660980224609375), SC_(0.14709429758897851782623104453504062279048901484918), SC_(-0.17120780885496551232352932901235943774904473019944) }},
      {{ SC_(32.0), SC_(0.826751708984375), SC_(0.18197608635110136442722424209924919380946511973609), SC_(0.064598428569533734464113024874557402334768980022172) }},
      {{ SC_(32.0), SC_(0.93773555755615234375), SC_(-0.061512016664104396409494145001588438528631649237376), SC_(0.36010369834698605740012216441227373597825633684005) }},
      {{ SC_(33.0), SC_(-0.74602639675140380859375), SC_(-0.010238220971698350467857407217583972140726845648941), SC_(0.26483415891807978747956511959896313413438051711664) }},
      {{ SC_(33.0), SC_(-0.72904598712921142578125), SC_(-0.1308485763851203410864936505227876528881511136519), SC_(0.16199934006548616731309863119775152390583901324519) }},
      {{ SC_(33.0), SC_(-0.5579319000244140625), SC_(-0.12577548566890528018101278253700971908249029962743), SC_(-0.13213214605592102018000812058769351569734360406003) }},
      {{ SC_(33.0), SC_(-0.38366591930389404296875), SC_(-0.084070866208971510118625762007538569384131026389396), SC_(-0.18256278466727144314587766075483055968035831220494) }},
      {{ SC_(33.0), SC_(0.264718532562255859375), SC_(0.060892666049180052331868898508597370624428803024817), SC_(0.19866890409777954034785008801181600022935344886198) }},
      {{ SC_(33.0), SC_(0.62944734096527099609375), SC_(-0.11433728271514716149262038842691043741855456620044), SC_(0.16755876228487195768012212741139439591382292792337) }},
      {{ SC_(33.0), SC_(0.67001712322235107421875), SC_(-0.081236062053488889130078168052517557727777089991736), SC_(-0.21649027108290998691804424765459226889986656795972) }},
      {{ SC_(33.0), SC_(0.81158387660980224609375), SC_(0.054836608100875136695247613465739163323207341583917), SC_(-0.26983701252599468973584716961923532939147494467454) }},
      {{ SC_(33.0), SC_(0.826751708984375), SC_(0.17096451544704338934795787534509579387648987239154), SC_(-0.10583253904494668067403419241018401345294284279768) }},
      {{ SC_(33.0), SC_(0.93773555755615234375), SC_(0.021689551526675134145413087356244487320455743955836), SC_(0.36566095216176988383802606024502153062571425905414) }},
      {{ SC_(38.0), SC_(-0.74602639675140380859375), SC_(-0.084123836557398448368713685848077796605866311328419), SC_(0.20927452879651299362933031503631704855861507328485) }},
      {{ SC_(38.0), SC_(-0.72904598712921142578125), SC_(-0.15529625891826503441381053635222357317586896447525), SC_(0.0095728141123042996678374510905606631222574103483576) }},
      {{ SC_(38.0), SC_(-0.5579319000244140625), SC_(0.098453621336514494698473554065871517874604718865768), SC_(-0.15887228344501787123307716070402047502579097616639) }},
      {{ SC_(38.0), SC_(-0.38366591930389404296875), SC_(0.1142998723616291395401060145662954970184529162179), SC_(0.10927652072714659779878476348183517273638952750771) }},
      {{ SC_(38.0), SC_(0.264718532562255859375), SC_(0.082342405948218235800013849335056084637027957309688), SC_(0.15992426917043357157539330709673818274284050011282) }},
      {{ SC_(38.0), SC_(0.62944734096527099609375), SC_(-0.068455729281013919450961847170789295612305662562268), SC_(-0.20232791952033959865517436817152841139901171805722) }},
      {{ SC_(38.0), SC_(0.67001712322235107421875), SC_(0.14923503774161864776328729535793778940014260423005), SC_(-0.00081555462858474175721539924197608607382214710104177) }},
      {{ SC_(38.0), SC_(0.81158387660980224609375), SC_(-0.054544375275263481570647398342926037642622621118648), SC_(0.24995338198241340981855015694448657310842038102797) }},
      {{ SC_(38.0), SC_(0.826751708984375), SC_(-0.16721624694409901980215061835708625790102572947942), SC_(0.059275472334568365380770389586353873529433513464428) }},
      {{ SC_(38.0), SC_(0.93773555755615234375), SC_(0.20855301957399606773775871068964050472366514949047), SC_(-0.10030484670657737103060450542322599342156588398843) }},
      {{ SC_(42.0), SC_(-0.74602639675140380859375), SC_(0.049566019304086784068530075774279790089365026819016), SC_(-0.2223326328142980698042327834311390349548637605267) }},
      {{ SC_(42.0), SC_(-0.72904598712921142578125), SC_(0.14591441453221755504339013126253144361512927416181), SC_(-0.03816847032424030854934985301169674005663852971074) }},
      {{ SC_(42.0), SC_(-0.5579319000244140625), SC_(-0.13430204358943900275964577227355331227334636201161), SC_(0.0051973684528497691222879613574650304460896053520729) }},
      {{ SC_(42.0), SC_(-0.38366591930389404296875), SC_(0.065763896800574200794337123835235188691341407252599), SC_(-0.1713134367479732947155934942710203117432539046046) }},
      {{ SC_(42.0), SC_(0.264718532562255859375), SC_(-0.047554509216288149280305803250205697401306151867419), SC_(0.18095441384071096874666701309266904943143926028736) }},
      {{ SC_(42.0), SC_(0.62944734096527099609375), SC_(0.10935216508815166523730605326515550073363675346191), SC_(0.1343668237290581228732195022404437327151868599812) }},
      {{ SC_(42.0), SC_(0.67001712322235107421875), SC_(-0.13896760821264559453299826838169576033084249809532), SC_(0.046166285445723758516981086429175967795330032118854) }},
      {{ SC_(42.0), SC_(0.81158387660980224609375), SC_(0.13257761059856394025891806012454608734090842373859), SC_(-0.14099679657580961322235886444766213263432122864624) }},
      {{ SC_(42.0), SC_(0.826751708984375), SC_(0.14083726257982003772240761087663193372628899052788), SC_(0.12939522669379464935358907263220136856872326106689) }},
      {{ SC_(42.0), SC_(0.93773555755615234375), SC_(-0.030227297367381724405890694551090646808341233639839), SC_(-0.32263036348629243619745931620595788155104891833781) }},
      {{ SC_(47.0), SC_(-0.74602639675140380859375), SC_(0.10555867750979365926641158999955582823336205722782), SC_(-0.14886382691569576113160226420850148145570650896964) }},
      {{ SC_(47.0), SC_(-0.72904598712921142578125), SC_(0.12518796913926798559687521769888776380193823473818), SC_(0.098180244656107285818363063590386661434884234727998) }},
      {{ SC_(47.0), SC_(-0.5579319000244140625), SC_(0.019958376774871797942991524370694468827252910590651), SC_(-0.19713453245538155745224332261651795745681090546712) }},
      {{ SC_(47.0), SC_(-0.38366591930389404296875), SC_(-0.017374612252196858651395396286373314512171227712276), SC_(0.18725030551272538736891544492946995866076663640595) }},
      {{ SC_(47.0), SC_(0.264718532562255859375), SC_(-0.018801793887180091986096938136652872878107965315931), SC_(0.1828072182041642441226028996345379902315722570693) }},
      {{ SC_(47.0), SC_(0.62944734096527099609375), SC_(-0.10497355122531684338594399243517694074545593042325), SC_(0.12395441308292615650354652321967372630461017577647) }},
      {{ SC_(47.0), SC_(0.67001712322235107421875), SC_(0.042375691594523493089898030922098260697978949901084), SC_(-0.20027976349819205062196975868907081288964978457637) }},
      {{ SC_(47.0), SC_(0.81158387660980224609375), SC_(-0.12720249332232236538255468589569255750641552199498), SC_(0.12911204921470701304207453622146811162549192306205) }},
      {{ SC_(47.0), SC_(0.826751708984375), SC_(-0.11972156572489977935845748400575031716451757509736), SC_(-0.15299307930087258161082851169709559917733372444518) }},
      {{ SC_(47.0), SC_(0.93773555755615234375), SC_(-0.18448824265114203879229766781768231984156422989655), SC_(0.10574076834730194623398317285604209247245691580845) }},
      {{ SC_(50.0), SC_(-0.74602639675140380859375), SC_(-0.015930599657360476251420277903683541838529410897537), SC_(-0.21465912896739233133099578206788459237386714150655) }},
      {{ SC_(50.0), SC_(-0.72904598712921142578125), SC_(0.12409002491708828479268113070514774903536846383229), SC_(-0.086287169891479867966715770145964370224141052863963) }},
      {{ SC_(50.0), SC_(-0.5579319000244140625), SC_(-0.005798165247856899753189081564247189672477629817479), SC_(-0.19337852580649058999917721542653095981057374271772) }},
      {{ SC_(50.0), SC_(-0.38366591930389404296875), SC_(-0.059497023650103635064046099627669865791536750381894), SC_(0.15794384507010689572165607053156094367974620258235) }},
      {{ SC_(50.0), SC_(0.264718532562255859375), SC_(-0.065209573905631036859687403696160942576965840778783), SC_(-0.14751871407424188124249576268838594921576865374728) }},
      {{ SC_(50.0), SC_(0.62944734096527099609375), SC_(0.1254648614906361354063479552814166773167878049504), SC_(-0.034440129398110338581115403924597511980186351811602) }},
      {{ SC_(50.0), SC_(0.67001712322235107421875), SC_(-0.10619347339517479426067516348745796102076178371881), SC_(0.11862572725603045508458932631769711812763534799817) }},
      {{ SC_(50.0), SC_(0.81158387660980224609375), SC_(0.11273074165283415173181149763996018303702643671155), SC_(0.14790659055314203028889130297212665219056965725573) }},
      {{ SC_(50.0), SC_(0.826751708984375), SC_(-0.066592210444900044500145874300565502648306521922739), SC_(0.21057227237727695731942424868416443302373930752217) }},
      {{ SC_(50.0), SC_(0.93773555755615234375), SC_(-0.02964420684396612633089666751568875846128660261089), SC_(0.29554119190479578704553201067740518317569997711165) }},
      {{ SC_(74.0), SC_(-0.74602639675140380859375), SC_(-0.11276175922769771071169791815382160822979193457584), SC_(-0.016948886125033992210699876903298192468926010338659) }},
      {{ SC_(74.0), SC_(-0.72904598712921142578125), SC_(0.043325082362381951121810614501313351872910740229927), SC_(-0.16177588767320896275870106383776756479873939526599) }},
      {{ SC_(74.0), SC_(-0.5579319000244140625), SC_(-0.10080435030792016569597859069478841148013073447729), SC_(0.018251782587574233476818350810881185458410525739317) }},
      {{ SC_(74.0), SC_(-0.38366591930389404296875), SC_(0.046884436541549348713098747004974391148402679382921), SC_(-0.13193735158761539160783845591049668332581458959337) }},
      {{ SC_(74.0), SC_(0.264718532562255859375), SC_(-0.041828012721919454058249300993966878486562319326719), SC_(-0.13246532996002790918584053275877515690218265371078) }},
      {{ SC_(74.0), SC_(0.62944734096527099609375), SC_(-0.094030311892407800682586230577407806078989970029721), SC_(-0.072919542245915760263666497413547057327808714299635) }},
      {{ SC_(74.0), SC_(0.67001712322235107421875), SC_(0.029245586267240350595851651237554590988267446471066), SC_(0.16214505190101967431610553130957058464946341991298) }},
      {{ SC_(74.0), SC_(0.81158387660980224609375), SC_(-0.017184547316074253794515299386081262373448628108694), SC_(-0.18803727598401509696193566641796932606576440421714) }},
      {{ SC_(74.0), SC_(0.826751708984375), SC_(0.11918365992241106370554467669124109309788511498893), SC_(0.049271190137184585759693541797865288317081249630842) }},
      {{ SC_(74.0), SC_(0.93773555755615234375), SC_(0.13720035943050209633696665899170965118560455647167), SC_(-0.11934635271777084702112356352205097073497522539851) }},
      {{ SC_(83.0), SC_(-0.74602639675140380859375), SC_(0.099722551700102296576333533087493494141629020623715), SC_(0.060920145263796023814234079688232261856372810771644) }},
      {{ SC_(83.0), SC_(-0.72904598712921142578125), SC_(-0.082673563441569816515278309758665439909493115318683), SC_(0.10304666821416430755952808837580442197138532186102) }},
      {{ SC_(83.0), SC_(-0.5579319000244140625), SC_(-0.071469557226080465580663942218061835065596029503675), SC_(0.10032073353554464505277586981830025137954384680805) }},
      {{ SC_(83.0), SC_(-0.38366591930389404296875), SC_(0.090342825331683058526707865550737058600999436851883), SC_(0.015229849936687863148217151178879823068202772258005) }},
      {{ SC_(83.0), SC_(0.264718532562255859375), SC_(0.032973965659052868308616011181565750057675408468301), SC_(-0.12971015008879036949215807951525454450331853071241) }},
      {{ SC_(83.0), SC_(0.62944734096527099609375), SC_(-0.029540121157521228269021443084960584105688041972903), SC_(0.14851201098143861160585951812951951622661772174285) }},
      {{ SC_(83.0), SC_(0.67001712322235107421875), SC_(0.10122142405146658235259251832888419156202562486693), SC_(0.0077420083935597411748271095780871224198331320212672) }},
      {{ SC_(83.0), SC_(0.81158387660980224609375), SC_(0.057246164186558041309336522292709213691507098187941), SC_(-0.15527890012859959180010630068393674149758957305009) }},
      {{ SC_(83.0), SC_(0.826751708984375), SC_(0.046180391617246980558614459450209311982173717330398), SC_(0.16785562098976736293735241808043927696415685748103) }},
      {{ SC_(83.0), SC_(0.93773555755615234375), SC_(-0.12572490913391149598157598741888682182134531126631), SC_(0.12308046852619065606878331099164630107367082534757) }},
      {{ SC_(101.0), SC_(-0.74602639675140380859375), SC_(0.058653496347056952338276621328805913660326830178208), SC_(0.12145297221972220508843876281155663375125894189862) }},
      {{ SC_(101.0), SC_(-0.72904598712921142578125), SC_(-0.090473034865819302928187941359278959062428518755725), SC_(-0.049121669560248310898765467668228847931197026959131) }},
      {{ SC_(101.0), SC_(-0.5579319000244140625), SC_(0.032856366144512093838472879802827945157670404434094), SC_(0.12642835711847836774479013663589314743072554059549) }},
      {{ SC_(101.0), SC_(-0.38366591930389404296875), SC_(-0.063163736094262211023950792526928416942278796176713), SC_(0.08315035982603328572025956598160739433185168321863) }},
      {{ SC_(101.0), SC_(0.264718532562255859375), SC_(0.071163045255901039101130479356531344296261959626307), SC_(0.059605104967104404152251553269156920601599226776817) }},
      {{ SC_(101.0), SC_(0.62944734096527099609375), SC_(-0.0007727131004341142524741554693628840685676674658113), SC_(-0.14111849131537663857555529499523590733520446597943) }},
      {{ SC_(101.0), SC_(0.67001712322235107421875), SC_(-0.070407995641034625719001861506953232343608676996959), SC_(-0.092817700559800711222725905975289230096607292859021) }},
      {{ SC_(101.0), SC_(0.81158387660980224609375), SC_(0.099307321362112185306610136683788343902740025414221), SC_(0.046418617748086995449796412250804429903067746389578) }},
      {{ SC_(101.0), SC_(0.826751708984375), SC_(-0.1041094321529210978436084887455176793203883621926), SC_(0.027652245608769378268189646446135419146885683214923) }},
      {{ SC_(101.0), SC_(0.93773555755615234375), SC_(-0.10613119080999585675059148209842336075096154309699), SC_(0.12944930189574758589151748582113145300025202556463) }},
      {{ SC_(103.0), SC_(-0.74602639675140380859375), SC_(-0.069509159753968058194042786081992949167966470822951), SC_(0.1042540571293701201528028813211055287246877892261) }},
      {{ SC_(103.0), SC_(-0.72904598712921142578125), SC_(0.025263082930279778421327606486190138820142052030236), SC_(-0.14351968257852565285920081107438326042937783381617) }},
      {{ SC_(103.0), SC_(-0.5579319000244140625), SC_(-0.086090797701103710780927800364190497383336250842762), SC_(0.73563687415286537614692801503996295947038747498055e-4) }},
      {{ SC_(103.0), SC_(-0.38366591930389404296875), SC_(0.0069903138700112647861271558581807248069002924998414), SC_(-0.12772502121884169194613640292720812041466814164591) }},
      {{ SC_(103.0), SC_(0.264718532562255859375), SC_(-0.041410666477160831448449369636364604203824717736859), SC_(-0.10726985707386768666039161492413816004770025158786) }},
      {{ SC_(103.0), SC_(0.62944734096527099609375), SC_(-0.086869296604861708037479158615097773729001515720048), SC_(0.030189104543447976063127397009596619632060749539848) }},
      {{ SC_(103.0), SC_(0.67001712322235107421875), SC_(-0.05108553281416170397625929563635477985617692288556), SC_(0.11834130734691348519983812797384944794665350021719) }},
      {{ SC_(103.0), SC_(0.81158387660980224609375), SC_(0.058956687321621474446809458105596372447480179278297), SC_(-0.131908419975604481181323208249846590177155219106) }},
      {{ SC_(103.0), SC_(0.826751708984375), SC_(-0.021621095970943942775281831322383200051308475737036), SC_(0.16069626010796515826935041981775936523380391638463) }},
      {{ SC_(103.0), SC_(0.93773555755615234375), SC_(-0.026566877946901700789372137814260494007273459963555), SC_(0.20481046345010719355266366241281814363105606775192) }},
      {{ SC_(110.0), SC_(-0.74602639675140380859375), SC_(-0.033942958151465668508584449603964158663794075720858), SC_(-0.13602869614463514275977560482278281839843937232776) }},
      {{ SC_(110.0), SC_(-0.72904598712921142578125), SC_(0.061608143475272538317308473633212181102846034412592), SC_(0.10678453148405205098663916975358345244841432153652) }},
      {{ SC_(110.0), SC_(-0.5579319000244140625), SC_(0.070207133539044196827310003993778517549356416945079), SC_(0.070477582350084174929316416542386486473261420732256) }},
      {{ SC_(110.0), SC_(-0.38366591930389404296875), SC_(-0.070383145106891206011892398176473132776246310124518), SC_(-0.056304633257010713541779389121079213335581039992689) }},
      {{ SC_(110.0), SC_(0.264718532562255859375), SC_(0.018413502281400223048564975179622159141770330579945), SC_(0.1179172684960028730149587291496622038750077559426) }},
      {{ SC_(110.0), SC_(0.62944734096527099609375), SC_(-0.084946393685047629698742653748849213204262536726215), SC_(0.02212137389603911574713594832891805519677492495707) }},
      {{ SC_(110.0), SC_(0.67001712322235107421875), SC_(-0.075205818842405280724589166472562327621104655346223), SC_(0.072065721597278484368730413339141193881824291866732) }},
      {{ SC_(110.0), SC_(0.81158387660980224609375), SC_(0.057209406868467160414288975624360868544196124966652), SC_(0.12749587894184737263697744890517205077643805330212) }},
      {{ SC_(110.0), SC_(0.826751708984375), SC_(-0.074856792842343494297327888969538339348549563347874), SC_(-0.10696602381164176466519470638170406570388141831222) }},
      {{ SC_(110.0), SC_(0.93773555755615234375), SC_(0.097528283970739845680724641236094845179184947489201), SC_(-0.13210730523293428301663298753017310169984684526741) }},
      {{ SC_(111.0), SC_(-0.74602639675140380859375), SC_(-0.032200675894540407249249527986931235112743426249519), SC_(0.13636975986133435085016449724426916756505823281803) }},
      {{ SC_(111.0), SC_(-0.72904598712921142578125), SC_(0.0016092508123221426259782618321854563885148486902523), SC_(-0.14344152276755107203423370387654056491916060539013) }},
      {{ SC_(111.0), SC_(-0.5579319000244140625), SC_(-0.0019266546022300930027573050620657297985689216768549), SC_(-0.13025449845936477071498681592486478446863468033711) }},
      {{ SC_(111.0), SC_(-0.38366591930389404296875), SC_(-0.00607083307494418231810803422278831700786776274005), SC_(0.12314301905657725821736747827712979258060988004664) }},
      {{ SC_(111.0), SC_(0.264718532562255859375), SC_(0.076917600598861354810476795406500521438714159220046), SC_(0.0033075920020254493876180380438220398526976541180716) }},
      {{ SC_(111.0), SC_(0.62944734096527099609375), SC_(-0.042334521409296933382182292266822707946314463083643), SC_(0.11707980002880993162285312441701953239742048843854) }},
      {{ SC_(111.0), SC_(0.67001712322235107421875), SC_(-0.01625732237213437043904647280255024284754469471479), SC_(0.13536990666014865190613699141291179267903978819174) }},
      {{ SC_(111.0), SC_(0.81158387660980224609375), SC_(0.093429234850716867173081121412126317601100287085826), SC_(0.050740491224134820431672350744872870880796379842562) }},
      {{ SC_(111.0), SC_(0.826751708984375), SC_(-0.099746842249768677069851749588989036311889774927283), SC_(-0.02218254391038425158040959896075971134469612198156) }},
      {{ SC_(111.0), SC_(0.93773555755615234375), SC_(0.061960098625334578699531381570226002216446334987954), SC_(-0.17630158114468011704453109150917307426932700963538) }},
      {{ SC_(115.0), SC_(-0.74602639675140380859375), SC_(0.011659882634088537821264971193347238274907192891989), SC_(-0.1417288093884680768867130033428123726827027042855) }},
      {{ SC_(115.0), SC_(-0.72904598712921142578125), SC_(0.0097131893606856202751128572690136150201795716231646), SC_(0.14012961153023905234915467648238152308202483249179) }},
      {{ SC_(115.0), SC_(-0.5579319000244140625), SC_(-0.055599872031625140506136394171510860309410123809349), SC_(0.093594483130628843819694780782575925754784924670163) }},
      {{ SC_(115.0), SC_(-0.38366591930389404296875), SC_(0.077050446497529102420650609981634503271775399693683), SC_(0.0088565512206407663055683543736671275288183109816667) }},
      {{ SC_(115.0), SC_(0.264718532562255859375), SC_(0.034359839114246272577599724967370326173387403660347), SC_(0.10578248128418573373870536860675213912264059240692) }},
      {{ SC_(115.0), SC_(0.62944734096527099609375), SC_(0.0082643990325571512244908953318239675941855106132265), SC_(-0.13165640504236233394765218021604504786233485133267) }},
      {{ SC_(115.0), SC_(0.67001712322235107421875), SC_(-0.0015721055642368064825337799606692523719130974520218), SC_(-0.1353286900783831392195565600906463227612561145681) }},
      {{ SC_(115.0), SC_(0.81158387660980224609375), SC_(-0.054210930576897856499034808655933306801074683806062), SC_(-0.12659507936588546926051398902517626516964689218928) }},
      {{ SC_(115.0), SC_(0.826751708984375), SC_(0.06212883372643213611372963364539976692767234086995), SC_(0.12103709534949250997508001328034108589273615963615) }},
      {{ SC_(115.0), SC_(0.93773555755615234375), SC_(-0.09980919675793132053530446510639647979845319955803), SC_(-0.12070840338940873219064713828143611372512223844091) }},
      {{ SC_(116.0), SC_(-0.74602639675140380859375), SC_(-0.068487247444151474237653315277483909414503521300912), SC_(0.093133560384715286625946002729620416337163521029867) }},
      {{ SC_(116.0), SC_(-0.72904598712921142578125), SC_(0.053747789206590672037151315696697693783833792642693), SC_(-0.11211897478819628686868719378051029417346515093252) }},
      {{ SC_(116.0), SC_(-0.5579319000244140625), SC_(0.080122819627702864075844102189789799443576781457988), SC_(0.020173351559352067990742477146036299831908728103273) }},
      {{ SC_(116.0), SC_(-0.38366591930389404296875), SC_(-0.024249827411491278686372542928360990815946534826784), SC_(-0.11467110049800068759284312552536360348652573880772) }},
      {{ SC_(116.0), SC_(0.264718532562255859375), SC_(0.073718014154393579573780297435185676405997097861731), SC_(-0.023941183188976671650101777466534611583995107650774) }},
      {{ SC_(116.0), SC_(0.62944734096527099609375), SC_(-0.059668625982518363289929597563274657874779402078409), SC_(-0.09255759087664323717343674706577199358384636772319) }},
      {{ SC_(116.0), SC_(0.67001712322235107421875), SC_(-0.064729455762043452505626574517572044801030359192088), SC_(-0.088456402518418445483355798933259689021877395507254) }},
      {{ SC_(116.0), SC_(0.81158387660980224609375), SC_(-0.09069070444539916571162153776802786573166522696411), SC_(-0.0527625562114936996735580314666853717965865324919) }},
      {{ SC_(116.0), SC_(0.826751708984375), SC_(0.094306540731834905126868750171910154657206855132072), SC_(0.044969460070177494430473922626932676591613349156668) }},
      {{ SC_(116.0), SC_(0.93773555755615234375), SC_(-0.11977051432565183689355134402005152657631906753244), SC_(-0.058477756477300972556925093606746906197796783801524) }},
      {{ SC_(119.0), SC_(-0.74602639675140380859375), SC_(0.0087647065593993755222972658179029408444330186700542), SC_(0.13981912827212672744690925773170472610548387878822) }},
      {{ SC_(119.0), SC_(-0.72904598712921142578125), SC_(-0.020501605529893412888893201088044338252329402923723), SC_(-0.13478486824495203061528622211548575586334551817436) }},
      {{ SC_(119.0), SC_(-0.5579319000244140625), SC_(0.080036079293206370171512732389414344286704185353321), SC_(-0.0057776707755366365863380008852867161540142918927643) }},
      {{ SC_(119.0), SC_(-0.38366591930389404296875), SC_(0.0052218893934731418741815240011222420959400585517152), SC_(-0.11902359008249444427689952801477258632653373728298) }},
      {{ SC_(119.0), SC_(0.264718532562255859375), SC_(-0.041958445146548813480092404170567661553263062970998), SC_(0.096369084287714671301426340819694101521306372531871) }},
      {{ SC_(119.0), SC_(0.62944734096527099609375), SC_(0.026043742963778131871545929796683083958834802939707), SC_(0.12346064721462223505658160979882243719998039566685) }},
      {{ SC_(119.0), SC_(0.67001712322235107421875), SC_(0.018730148385420890536233247762177938725955754094692), SC_(0.12977342706190187482418503847938799787319981967217) }},
      {{ SC_(119.0), SC_(0.81158387660980224609375), SC_(-0.0051210369574630302606435588094752910907524904265636), SC_(0.14977897540214287229711857221722487285805056065051) }},
      {{ SC_(119.0), SC_(0.826751708984375), SC_(0.0070994904638281005505473502488606481760552210237098), SC_(-0.15244878741668898076438519389186244649902911784835) }},
      {{ SC_(119.0), SC_(0.93773555755615234375), SC_(-0.089511411656126705336943924861664813522610049042024), SC_(0.13442707735952316190476066030580938662981623871763) }}
   }};


