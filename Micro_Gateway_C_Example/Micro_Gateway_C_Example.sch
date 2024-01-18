<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="8.0.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Description" color="1" fill="1" visible="yes" active="yes"/>
<layer number="196" name="logo1" color="12" fill="1" visible="yes" active="yes"/>
<layer number="198" name="logo2" color="2" fill="1" visible="yes" active="yes"/>
<layer number="199" name="InfoNew" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="CANgraph">
<description>&lt;b&gt;MRS CANgraph library&lt;/b&gt;&lt;p&gt;
General library for graphical programming of all modules.

&lt;p&gt;&lt;hr&gt;&lt;p&gt;

&lt;b&gt;MRS CANgraph Bibliothek&lt;/b&gt;&lt;p&gt;
Allgemeine Bibliothek für die grafische Programmierung aller Module.</description>
<packages>
</packages>
<symbols>
<symbol name="FRAME">
<wire x1="-7.62" y1="-172.72" x2="43.18" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="43.18" y1="-172.72" x2="90.805" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="90.805" y1="-172.72" x2="138.43" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="138.43" y1="-172.72" x2="186.055" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="186.055" y1="-172.72" x2="233.68" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="252.73" y1="-172.72" x2="252.73" y2="-118.745" width="0.3048" layer="94"/>
<wire x1="252.73" y1="-118.745" x2="252.73" y2="-67.945" width="0.3048" layer="94"/>
<wire x1="252.73" y1="-67.945" x2="252.73" y2="-17.145" width="0.3048" layer="94"/>
<wire x1="252.73" y1="-17.145" x2="252.73" y2="6.35" width="0.3048" layer="94"/>
<wire x1="-7.62" y1="6.35" x2="-7.62" y2="-17.145" width="0.3048" layer="94"/>
<wire x1="-7.62" y1="-17.145" x2="-7.62" y2="-67.945" width="0.3048" layer="94"/>
<wire x1="-7.62" y1="-67.945" x2="-7.62" y2="-118.745" width="0.3048" layer="94"/>
<wire x1="-7.62" y1="-118.745" x2="-7.62" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="-4.445" y1="-169.545" x2="43.18" y2="-169.545" width="0.3048" layer="94"/>
<wire x1="43.18" y1="-169.545" x2="90.805" y2="-169.545" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-169.545" x2="249.555" y2="-164.465" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-164.465" x2="249.555" y2="-159.385" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-159.385" x2="249.555" y2="-154.305" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-154.305" x2="249.555" y2="-149.225" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-149.225" x2="249.555" y2="-118.745" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-118.745" x2="249.555" y2="-67.945" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-67.945" x2="249.555" y2="-17.145" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-17.145" x2="249.555" y2="3.175" width="0.3048" layer="94"/>
<wire x1="186.055" y1="3.175" x2="138.43" y2="3.175" width="0.3048" layer="94"/>
<wire x1="138.43" y1="3.175" x2="90.805" y2="3.175" width="0.3048" layer="94"/>
<wire x1="90.805" y1="3.175" x2="43.18" y2="3.175" width="0.3048" layer="94"/>
<wire x1="43.18" y1="3.175" x2="-4.445" y2="3.175" width="0.3048" layer="94"/>
<wire x1="-4.445" y1="3.175" x2="-4.445" y2="-17.145" width="0.3048" layer="94"/>
<wire x1="-4.445" y1="-17.145" x2="-4.445" y2="-67.945" width="0.3048" layer="94"/>
<wire x1="-4.445" y1="-67.945" x2="-4.445" y2="-118.745" width="0.3048" layer="94"/>
<wire x1="-4.445" y1="-118.745" x2="-4.445" y2="-169.545" width="0.3048" layer="94"/>
<wire x1="186.055" y1="6.35" x2="138.43" y2="6.35" width="0.3048" layer="94"/>
<wire x1="138.43" y1="6.35" x2="90.805" y2="6.35" width="0.3048" layer="94"/>
<wire x1="90.805" y1="6.35" x2="43.18" y2="6.35" width="0.3048" layer="94"/>
<wire x1="43.18" y1="6.35" x2="-7.62" y2="6.35" width="0.3048" layer="94"/>
<wire x1="186.055" y1="6.35" x2="186.055" y2="3.175" width="0.3048" layer="94"/>
<wire x1="186.055" y1="-169.545" x2="186.055" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="-7.62" y1="-67.945" x2="-4.445" y2="-67.945" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-17.145" x2="252.73" y2="-17.145" width="0.3048" layer="94"/>
<wire x1="90.805" y1="3.175" x2="90.805" y2="6.35" width="0.3048" layer="94"/>
<wire x1="90.805" y1="-169.545" x2="90.805" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="-7.62" y1="-118.745" x2="-4.445" y2="-118.745" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-67.945" x2="252.73" y2="-67.945" width="0.3048" layer="94"/>
<wire x1="-7.62" y1="-17.145" x2="-4.445" y2="-17.145" width="0.3048" layer="94"/>
<wire x1="43.18" y1="3.175" x2="43.18" y2="6.35" width="0.3048" layer="94"/>
<wire x1="249.555" y1="-118.745" x2="252.73" y2="-118.745" width="0.3048" layer="94"/>
<wire x1="138.43" y1="3.175" x2="138.43" y2="6.35" width="0.3048" layer="94"/>
<wire x1="233.68" y1="6.35" x2="233.68" y2="3.175" width="0.3048" layer="94"/>
<wire x1="233.68" y1="-169.545" x2="233.68" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="138.43" y1="-169.545" x2="138.43" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="43.18" y1="-172.72" x2="43.18" y2="-169.545" width="0.3048" layer="94"/>
<wire x1="149.225" y1="-169.545" x2="149.225" y2="-149.225" width="0.3048" layer="94"/>
<wire x1="149.225" y1="-149.225" x2="208.28" y2="-149.225" width="0.3048" layer="94"/>
<wire x1="208.28" y1="-149.225" x2="249.555" y2="-149.225" width="0.3048" layer="94"/>
<wire x1="239.395" y1="-169.545" x2="239.395" y2="-164.465" width="0.3048" layer="94"/>
<wire x1="239.395" y1="-164.465" x2="249.555" y2="-164.465" width="0.3048" layer="94"/>
<wire x1="239.395" y1="-164.465" x2="208.28" y2="-164.465" width="0.3048" layer="94"/>
<wire x1="208.28" y1="-164.465" x2="208.28" y2="-169.545" width="0.3048" layer="94"/>
<wire x1="208.28" y1="-164.465" x2="208.28" y2="-159.385" width="0.3048" layer="94"/>
<wire x1="208.28" y1="-159.385" x2="249.555" y2="-159.385" width="0.3048" layer="94"/>
<wire x1="208.28" y1="-159.385" x2="208.28" y2="-154.305" width="0.3048" layer="94"/>
<wire x1="208.28" y1="-154.305" x2="249.555" y2="-154.305" width="0.3048" layer="94"/>
<wire x1="208.28" y1="-154.305" x2="208.28" y2="-149.225" width="0.3048" layer="94"/>
<wire x1="249.555" y1="3.175" x2="186.055" y2="3.175" width="0.3048" layer="94"/>
<wire x1="252.73" y1="6.35" x2="186.055" y2="6.35" width="0.3048" layer="94"/>
<wire x1="90.805" y1="-169.545" x2="149.225" y2="-169.545" width="0.3048" layer="94"/>
<wire x1="149.225" y1="-169.545" x2="185.928" y2="-169.545" width="0.3048" layer="94"/>
<wire x1="186.309" y1="-169.545" x2="233.68" y2="-169.545" width="0.3048" layer="94"/>
<wire x1="233.807" y1="-169.545" x2="249.555" y2="-169.545" width="0.3048" layer="94"/>
<wire x1="233.807" y1="-172.72" x2="252.73" y2="-172.72" width="0.3048" layer="94"/>
<wire x1="191.008" y1="-159.131" x2="207.01" y2="-159.131" width="0.508" layer="100"/>
<wire x1="191.008" y1="-162.687" x2="207.01" y2="-162.687" width="0.508" layer="100"/>
<wire x1="207.01" y1="-162.687" x2="207.01" y2="-159.131" width="0.508" layer="100"/>
<wire x1="207.01" y1="-159.131" x2="207.01" y2="-150.495" width="0.508" layer="100"/>
<wire x1="207.01" y1="-150.495" x2="190.754" y2="-150.495" width="0.508" layer="100"/>
<wire x1="190.754" y1="-150.495" x2="190.754" y2="-162.687" width="0.508" layer="100"/>
<wire x1="191.77" y1="-161.925" x2="191.77" y2="-159.893" width="0.508" layer="100"/>
<wire x1="194.818" y1="-159.893" x2="194.818" y2="-161.925" width="0.508" layer="100"/>
<wire x1="197.612" y1="-159.893" x2="197.612" y2="-161.925" width="0.508" layer="100"/>
<wire x1="197.7644" y1="-159.8422" x2="199.3646" y2="-159.8422" width="0.381" layer="100"/>
<wire x1="199.3646" y1="-159.8422" x2="199.898" y2="-160.401" width="0.381" layer="100" curve="-90"/>
<wire x1="199.898" y1="-160.401" x2="199.39" y2="-160.909" width="0.381" layer="100" curve="-90"/>
<wire x1="199.39" y1="-160.909" x2="197.866" y2="-160.909" width="0.381" layer="100"/>
<wire x1="198.6788" y1="-160.9598" x2="199.7964" y2="-161.925" width="0.508" layer="100"/>
<wire x1="194.7164" y1="-159.8422" x2="193.2432" y2="-161.6202" width="0.381" layer="100"/>
<wire x1="193.2432" y1="-161.6202" x2="191.8716" y2="-159.8422" width="0.381" layer="100"/>
<wire x1="204.724" y1="-159.893" x2="203.2" y2="-159.893" width="0.381" layer="100"/>
<wire x1="203.2" y1="-159.893" x2="202.946" y2="-159.893" width="0.381" layer="100"/>
<wire x1="204.724" y1="-161.925" x2="202.692" y2="-161.925" width="0.381" layer="100"/>
<wire x1="202.692" y1="-161.925" x2="202.438" y2="-161.671" width="0.381" layer="100" curve="-90"/>
<wire x1="204.724" y1="-161.925" x2="204.978" y2="-161.671" width="0.381" layer="100" curve="90"/>
<wire x1="204.978" y1="-161.671" x2="204.978" y2="-161.163" width="0.381" layer="100"/>
<wire x1="204.978" y1="-161.163" x2="204.724" y2="-160.909" width="0.381" layer="100" curve="90"/>
<wire x1="202.692" y1="-160.909" x2="204.724" y2="-160.909" width="0.381" layer="100"/>
<wire x1="202.692" y1="-160.909" x2="202.438" y2="-160.655" width="0.381" layer="100" curve="-90"/>
<wire x1="202.438" y1="-160.655" x2="202.438" y2="-160.147" width="0.381" layer="100"/>
<wire x1="202.438" y1="-160.147" x2="202.692" y2="-159.893" width="0.381" layer="100" curve="-90"/>
<wire x1="202.692" y1="-159.893" x2="203.2" y2="-159.893" width="0.381" layer="100"/>
<wire x1="204.724" y1="-159.893" x2="204.978" y2="-160.147" width="0.381" layer="100" curve="-90"/>
<wire x1="197.612" y1="-152.527" x2="198.882" y2="-151.257" width="0.381" layer="100"/>
<wire x1="198.882" y1="-151.257" x2="200.152" y2="-152.527" width="0.381" layer="100"/>
<wire x1="200.152" y1="-152.527" x2="198.882" y2="-153.797" width="0.381" layer="100"/>
<wire x1="198.882" y1="-153.797" x2="197.612" y2="-152.527" width="0.381" layer="100"/>
<wire x1="198.882" y1="-151.511" x2="197.866" y2="-152.527" width="0.381" layer="100"/>
<wire x1="197.866" y1="-152.527" x2="198.882" y2="-153.543" width="0.381" layer="100"/>
<wire x1="198.882" y1="-153.543" x2="199.898" y2="-152.527" width="0.381" layer="100"/>
<wire x1="199.898" y1="-152.527" x2="199.136" y2="-151.765" width="0.381" layer="100"/>
<wire x1="199.136" y1="-151.765" x2="198.374" y2="-152.527" width="0.381" layer="100"/>
<wire x1="198.374" y1="-152.527" x2="198.12" y2="-152.527" width="0.381" layer="100"/>
<wire x1="198.12" y1="-152.527" x2="198.882" y2="-153.289" width="0.381" layer="100"/>
<wire x1="198.882" y1="-153.289" x2="199.644" y2="-152.527" width="0.381" layer="100"/>
<wire x1="199.644" y1="-152.527" x2="199.39" y2="-152.273" width="0.381" layer="100"/>
<wire x1="199.39" y1="-152.273" x2="199.136" y2="-152.019" width="0.381" layer="100"/>
<wire x1="199.136" y1="-152.019" x2="198.628" y2="-152.527" width="0.381" layer="100"/>
<wire x1="198.628" y1="-152.527" x2="198.628" y2="-152.781" width="0.381" layer="100"/>
<wire x1="198.628" y1="-152.781" x2="198.882" y2="-153.035" width="0.381" layer="100"/>
<wire x1="198.882" y1="-153.035" x2="198.882" y2="-152.781" width="0.381" layer="100"/>
<wire x1="198.882" y1="-152.781" x2="199.39" y2="-152.273" width="0.381" layer="100"/>
<wire x1="196.088" y1="-152.781" x2="191.77" y2="-152.781" width="0.381" layer="100"/>
<wire x1="191.77" y1="-152.781" x2="191.77" y2="-156.845" width="0.381" layer="100"/>
<wire x1="191.77" y1="-156.845" x2="194.31" y2="-156.845" width="0.381" layer="100"/>
<wire x1="194.31" y1="-156.845" x2="194.31" y2="-153.543" width="0.381" layer="100"/>
<wire x1="194.31" y1="-153.543" x2="198.882" y2="-158.115" width="0.381" layer="100"/>
<wire x1="198.882" y1="-158.115" x2="203.454" y2="-153.543" width="0.381" layer="100"/>
<wire x1="203.454" y1="-153.543" x2="203.454" y2="-156.845" width="0.381" layer="100"/>
<wire x1="203.454" y1="-156.845" x2="205.994" y2="-156.845" width="0.381" layer="100"/>
<wire x1="205.994" y1="-156.845" x2="205.994" y2="-152.781" width="0.381" layer="100"/>
<wire x1="205.994" y1="-152.781" x2="201.676" y2="-152.781" width="0.381" layer="100"/>
<wire x1="201.676" y1="-152.781" x2="198.882" y2="-155.575" width="0.381" layer="100"/>
<wire x1="198.882" y1="-155.575" x2="196.088" y2="-152.781" width="0.381" layer="100"/>
<wire x1="192.278" y1="-153.035" x2="192.278" y2="-156.591" width="0.762" layer="100"/>
<wire x1="192.278" y1="-156.591" x2="194.056" y2="-156.591" width="0.762" layer="100"/>
<wire x1="194.056" y1="-156.591" x2="194.056" y2="-153.035" width="0.762" layer="100"/>
<wire x1="194.056" y1="-153.035" x2="192.786" y2="-153.035" width="0.762" layer="100"/>
<wire x1="192.786" y1="-153.035" x2="192.786" y2="-156.083" width="0.762" layer="100"/>
<wire x1="192.786" y1="-156.083" x2="193.548" y2="-156.083" width="0.762" layer="100"/>
<wire x1="193.548" y1="-156.083" x2="193.548" y2="-153.289" width="0.762" layer="100"/>
<wire x1="193.548" y1="-153.289" x2="196.088" y2="-153.289" width="0.762" layer="100"/>
<wire x1="196.088" y1="-153.289" x2="199.644" y2="-156.845" width="0.762" layer="100"/>
<wire x1="199.644" y1="-156.845" x2="199.39" y2="-157.099" width="0.762" layer="100"/>
<wire x1="199.39" y1="-157.099" x2="198.882" y2="-157.607" width="0.762" layer="100"/>
<wire x1="198.882" y1="-157.607" x2="194.818" y2="-153.543" width="0.762" layer="100"/>
<wire x1="194.818" y1="-153.543" x2="195.834" y2="-153.543" width="0.762" layer="100"/>
<wire x1="195.834" y1="-153.543" x2="199.39" y2="-157.099" width="0.762" layer="100"/>
<wire x1="199.39" y1="-157.099" x2="203.2" y2="-153.289" width="0.762" layer="100"/>
<wire x1="203.2" y1="-153.289" x2="202.692" y2="-153.289" width="0.762" layer="100"/>
<wire x1="202.692" y1="-153.289" x2="201.676" y2="-153.289" width="0.762" layer="100"/>
<wire x1="201.676" y1="-153.289" x2="199.39" y2="-155.575" width="0.762" layer="100"/>
<wire x1="199.39" y1="-155.575" x2="199.898" y2="-156.083" width="0.762" layer="100"/>
<wire x1="199.898" y1="-156.083" x2="202.692" y2="-153.289" width="0.762" layer="100"/>
<wire x1="202.692" y1="-153.289" x2="205.74" y2="-153.289" width="0.762" layer="100"/>
<wire x1="205.74" y1="-153.289" x2="205.74" y2="-156.337" width="0.762" layer="100"/>
<wire x1="205.74" y1="-156.337" x2="203.708" y2="-156.337" width="0.762" layer="100"/>
<wire x1="203.708" y1="-156.337" x2="203.708" y2="-153.797" width="0.762" layer="100"/>
<wire x1="203.708" y1="-153.797" x2="205.232" y2="-153.797" width="0.762" layer="100"/>
<wire x1="205.232" y1="-153.797" x2="205.232" y2="-155.829" width="0.762" layer="100"/>
<wire x1="205.232" y1="-155.829" x2="204.216" y2="-155.829" width="0.762" layer="100"/>
<wire x1="204.216" y1="-155.829" x2="204.216" y2="-154.305" width="0.762" layer="100"/>
<wire x1="204.216" y1="-154.305" x2="204.724" y2="-154.305" width="0.762" layer="100"/>
<wire x1="204.724" y1="-154.305" x2="204.724" y2="-155.321" width="0.762" layer="100"/>
<text x="16.764" y="-172.466" size="2.1844" layer="94" font="vector">A</text>
<text x="66.802" y="-172.466" size="2.1844" layer="94" font="vector">B</text>
<text x="113.538" y="-172.466" size="2.1844" layer="94" font="vector">C</text>
<text x="161.798" y="-172.466" size="2.1844" layer="94" font="vector">D</text>
<text x="209.296" y="-172.466" size="2.1844" layer="94" font="vector">E</text>
<text x="247.142" y="-172.466" size="2.1844" layer="94" font="vector">F</text>
<text x="250.444" y="-144.018" size="2.1844" layer="94" font="vector">1</text>
<text x="250.19" y="-93.218" size="2.1844" layer="94" font="vector">2</text>
<text x="250.19" y="-42.418" size="2.1844" layer="94" font="vector">3</text>
<text x="208.28" y="3.556" size="2.1844" layer="94" font="vector">E</text>
<text x="160.528" y="3.556" size="2.1844" layer="94" font="vector">D</text>
<text x="113.284" y="3.556" size="2.1844" layer="94" font="vector">C</text>
<text x="65.278" y="3.556" size="2.1844" layer="94" font="vector">B</text>
<text x="16.764" y="3.556" size="2.1844" layer="94" font="vector">A</text>
<text x="-6.858" y="-42.418" size="2.1844" layer="94" font="vector">3</text>
<text x="-6.858" y="-93.472" size="2.1844" layer="94" font="vector">2</text>
<text x="-6.604" y="-146.05" size="2.1844" layer="94" font="vector">1</text>
<text x="210.185" y="-158.115" size="2.1844" layer="94" font="vector">&gt;DRAWING_NAME</text>
<text x="210.185" y="-163.195" size="2.1844" layer="94" font="vector">&gt;LAST_DATE_TIME</text>
<text x="223.52" y="-168.275" size="2.1844" layer="94" font="vector">&gt;SHEET</text>
<text x="209.931" y="-168.402" size="2.1844" layer="94" font="vector">Blatt:</text>
<text x="242.062" y="3.556" size="2.1844" layer="94" font="vector">F</text>
<text x="249.936" y="-4.572" size="2.1844" layer="94" font="vector">4</text>
<text x="-7.112" y="-4.572" size="2.1844" layer="94" font="vector">4</text>
<text x="151.384" y="-164.084" size="6.4516" layer="196" font="vector" ratio="14">CAN</text>
<text x="169.418" y="-163.322" size="3.81" layer="100" font="vector" ratio="14">graph</text>
<text x="151.384" y="-167.386" size="1.524" layer="196" font="vector">CAN-Bus freie Programmierung</text>
<text x="209.931" y="-153.162" size="2.1844" layer="94" font="vector">Press F12 to compile</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="CAN_FRAME" prefix="FRAME">
<description>&lt;b&gt;Frame for CANgraph&lt;/b&gt;&lt;p&gt;
Empty sheet. Several empty sheets can be used as frameworks for printing several sides, too.

&lt;p&gt;&lt;hr&gt;&lt;p&gt;

&lt;b&gt;Rahmen für CANgraph&lt;/b&gt;&lt;p&gt;
Leeres Blatt. Es können auch mehrere leere Blätter als Rahmen zum Drucken mehrerer Seiten verwendet werden.</description>
<gates>
<gate name="CAN_FRAME" symbol="FRAME" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="FRAME1" library="CANgraph" deviceset="CAN_FRAME" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="FRAME1" gate="CAN_FRAME" x="-264.16" y="182.88"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
