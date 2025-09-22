#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void Num2Bits_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_0_run(uint ctx_index,Circom_CalcWit* ctx);
void LessThan_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void LessThan_1_run(uint ctx_index,Circom_CalcWit* ctx);
void DivRem_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void DivRem_2_run(uint ctx_index,Circom_CalcWit* ctx);
void DivRem_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void DivRem_3_run(uint ctx_index,Circom_CalcWit* ctx);
void Num2Bits_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_4_run(uint ctx_index,Circom_CalcWit* ctx);
void LessThan_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void LessThan_5_run(uint ctx_index,Circom_CalcWit* ctx);
void DivRem_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void DivRem_6_run(uint ctx_index,Circom_CalcWit* ctx);
void IsZero_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsZero_7_run(uint ctx_index,Circom_CalcWit* ctx);
void MultiMux1_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiMux1_8_run(uint ctx_index,Circom_CalcWit* ctx);
void Mux1_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Mux1_9_run(uint ctx_index,Circom_CalcWit* ctx);
void FizzBuzz_10_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void FizzBuzz_10_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[11] = { 
Num2Bits_0_run,
LessThan_1_run,
DivRem_2_run,
DivRem_3_run,
Num2Bits_4_run,
LessThan_5_run,
DivRem_6_run,
IsZero_7_run,
MultiMux1_8_run,
Mux1_9_run,
FizzBuzz_10_run };
Circom_TemplateFunction _functionTableParallel[11] = { 
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL };
uint get_main_input_signal_start() {return 16;}

uint get_main_input_signal_no() {return 15;}

uint get_total_signal_no() {return 1081;}

uint get_number_of_components() {return 271;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 526;}

uint get_size_of_constants() {return 13;}

uint get_size_of_io_map() {return 0;}

uint get_size_of_bus_field_map() {return 0;}

void release_memory_component(Circom_CalcWit* ctx, uint pos) {{

if (pos != 0){{

if(ctx->componentMemory[pos].subcomponents)
delete []ctx->componentMemory[pos].subcomponents;

if(ctx->componentMemory[pos].subcomponentsParallel)
delete []ctx->componentMemory[pos].subcomponentsParallel;

if(ctx->componentMemory[pos].outputIsSet)
delete []ctx->componentMemory[pos].outputIsSet;

if(ctx->componentMemory[pos].mutexes)
delete []ctx->componentMemory[pos].mutexes;

if(ctx->componentMemory[pos].cvs)
delete []ctx->componentMemory[pos].cvs;

if(ctx->componentMemory[pos].sbct)
delete []ctx->componentMemory[pos].sbct;

}}


}}


// function declarations
// template declarations
void Num2Bits_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "Num2Bits";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_0_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[4];
FrElement lvar[4];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 31
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)];
// load src
Fr_shr(&expaux[1],&signalValues[mySignalStart + 5],&lvar[3]); // line circom 32
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 32
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
Fr_sub(&expaux[2],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&circuitConstants[2]); // line circom 33
Fr_mul(&expaux[1],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&expaux[2]); // line circom 33
{{
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 33
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_mul(&expaux[1],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&lvar[2]); // line circom 34
Fr_add(&expaux[0],&lvar[1],&expaux[1]); // line circom 34
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&lvar[2]); // line circom 35
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
Fr_add(&expaux[0],&lvar[3],&circuitConstants[2]); // line circom 31
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 31
}
{
{{
Fr_eq(&expaux[0],&lvar[1],&signalValues[mySignalStart + 5]); // line circom 38
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 38. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void LessThan_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "LessThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void LessThan_1_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[3];
FrElement lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
std::string new_cmp_name = "n2b";
Num2Bits_0_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
if (!Fr_isTrue(&circuitConstants[2])) std::cout << "Failed assert in template/function " << myTemplateName << " line 90. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&circuitConstants[2]));
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 5];
// load src
Fr_add(&expaux[1],&signalValues[mySignalStart + 1],&circuitConstants[4]); // line circom 96
Fr_sub(&expaux[0],&expaux[1],&signalValues[mySignalStart + 2]); // line circom 96
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
Fr_sub(&expaux[0],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 4]); // line circom 98
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void DivRem_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "DivRem";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void DivRem_2_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[4];
FrElement lvar[2];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
std::string new_cmp_name = "lt";
LessThan_1_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
Fr_idiv(&expaux[0],&signalValues[mySignalStart + 2],&circuitConstants[5]); // line circom 15
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 1];
// load src
Fr_mod(&expaux[0],&signalValues[mySignalStart + 2],&circuitConstants[5]); // line circom 16
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
Fr_mul(&expaux[2],&circuitConstants[5],&signalValues[mySignalStart + 0]); // line circom 21
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 21
{{
Fr_eq(&expaux[0],&expaux[1],&signalValues[mySignalStart + 2]); // line circom 21
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 21. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
{{
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0],&circuitConstants[2]); // line circom 29
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 29. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void DivRem_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 3;
ctx->componentMemory[coffset].templateName = "DivRem";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void DivRem_3_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[4];
FrElement lvar[2];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
std::string new_cmp_name = "lt";
LessThan_1_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
Fr_idiv(&expaux[0],&signalValues[mySignalStart + 2],&circuitConstants[0]); // line circom 15
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 1];
// load src
Fr_mod(&expaux[0],&signalValues[mySignalStart + 2],&circuitConstants[0]); // line circom 16
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
Fr_mul(&expaux[2],&circuitConstants[0],&signalValues[mySignalStart + 0]); // line circom 21
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 21
{{
Fr_eq(&expaux[0],&expaux[1],&signalValues[mySignalStart + 2]); // line circom 21
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 21. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
{{
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0],&circuitConstants[2]); // line circom 29
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 29. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Num2Bits_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 4;
ctx->componentMemory[coffset].templateName = "Num2Bits";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_4_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[4];
FrElement lvar[4];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[6]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[6]); // line circom 31
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)];
// load src
Fr_shr(&expaux[1],&signalValues[mySignalStart + 6],&lvar[3]); // line circom 32
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 32
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
Fr_sub(&expaux[2],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&circuitConstants[2]); // line circom 33
Fr_mul(&expaux[1],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&expaux[2]); // line circom 33
{{
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 33
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_mul(&expaux[1],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&lvar[2]); // line circom 34
Fr_add(&expaux[0],&lvar[1],&expaux[1]); // line circom 34
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&lvar[2]); // line circom 35
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
Fr_add(&expaux[0],&lvar[3],&circuitConstants[2]); // line circom 31
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[6]); // line circom 31
}
{
{{
Fr_eq(&expaux[0],&lvar[1],&signalValues[mySignalStart + 6]); // line circom 38
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 38. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void LessThan_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 5;
ctx->componentMemory[coffset].templateName = "LessThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void LessThan_5_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[3];
FrElement lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
std::string new_cmp_name = "n2b";
Num2Bits_4_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
if (!Fr_isTrue(&circuitConstants[2])) std::cout << "Failed assert in template/function " << myTemplateName << " line 90. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&circuitConstants[2]));
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 6];
// load src
Fr_add(&expaux[1],&signalValues[mySignalStart + 1],&circuitConstants[7]); // line circom 96
Fr_sub(&expaux[0],&expaux[1],&signalValues[mySignalStart + 2]); // line circom 96
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_4_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
Fr_sub(&expaux[0],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 5]); // line circom 98
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void DivRem_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 6;
ctx->componentMemory[coffset].templateName = "DivRem";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void DivRem_6_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[4];
FrElement lvar[2];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[8]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
std::string new_cmp_name = "lt";
LessThan_5_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
Fr_idiv(&expaux[0],&signalValues[mySignalStart + 2],&circuitConstants[8]); // line circom 15
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 1];
// load src
Fr_mod(&expaux[0],&signalValues[mySignalStart + 2],&circuitConstants[8]); // line circom 16
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
Fr_mul(&expaux[2],&circuitConstants[8],&signalValues[mySignalStart + 0]); // line circom 21
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 21
{{
Fr_eq(&expaux[0],&expaux[1],&signalValues[mySignalStart + 2]); // line circom 21
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 21. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[8]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
{{
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0],&circuitConstants[2]); // line circom 29
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 29. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void IsZero_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 7;
ctx->componentMemory[coffset].templateName = "IsZero";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void IsZero_7_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[3];
FrElement lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
Fr_neq(&expaux[0],&signalValues[mySignalStart + 1],&circuitConstants[1]); // line circom 30
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + 2];
// load src
Fr_div(&expaux[0],&circuitConstants[2],&signalValues[mySignalStart + 1]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}else{
{
PFrElement aux_dest = &signalValues[mySignalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
Fr_neg(&expaux[2],&signalValues[mySignalStart + 1]); // line circom 32
Fr_mul(&expaux[1],&expaux[2],&signalValues[mySignalStart + 2]); // line circom 32
Fr_add(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 32
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
Fr_mul(&expaux[1],&signalValues[mySignalStart + 1],&signalValues[mySignalStart + 0]); // line circom 33
{{
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 33
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiMux1_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 8;
ctx->componentMemory[coffset].templateName = "MultiMux1";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 3;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void MultiMux1_8_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[3];
FrElement lvar[2];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 26
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
Fr_sub(&expaux[2],&signalValues[mySignalStart + 2],&signalValues[mySignalStart + 1]); // line circom 28
Fr_mul(&expaux[1],&expaux[2],&signalValues[mySignalStart + 3]); // line circom 28
Fr_add(&expaux[0],&expaux[1],&signalValues[mySignalStart + 1]); // line circom 28
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 26
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Mux1_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 9;
ctx->componentMemory[coffset].templateName = "Mux1";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 3;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void Mux1_9_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[2];
FrElement lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
std::string new_cmp_name = "mux";
MultiMux1_8_create(mySignalStart+4,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[9]); // line circom 41
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((0 + (1 * Fr_toInt(&lvar[0]))) + 1)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 1)]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 41
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[9]); // line circom 41
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 3]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
MultiMux1_8_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0]);
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void FizzBuzz_10_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 10;
ctx->componentMemory[coffset].templateName = "FizzBuzz";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 15;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[135]{0};
}

void FizzBuzz_10_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[2];
FrElement lvar[3];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
uint aux_create = 0;
int aux_cmp_num = 45+ctx_index+1;
uint csoffset = mySignalStart+225;
uint aux_dimensions[1] = {15};
for (uint i = 0; i < 15; i++) {
std::string new_cmp_name = "divRem3"+ctx->generate_position_array(aux_dimensions, 1, i);
DivRem_2_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 12 ;
aux_cmp_num += 3;
}
}
{
uint aux_create = 15;
int aux_cmp_num = 90+ctx_index+1;
uint csoffset = mySignalStart+405;
uint aux_dimensions[1] = {15};
for (uint i = 0; i < 15; i++) {
std::string new_cmp_name = "divRem5"+ctx->generate_position_array(aux_dimensions, 1, i);
DivRem_3_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 12 ;
aux_cmp_num += 3;
}
}
{
uint aux_create = 30;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+30;
uint aux_dimensions[1] = {15};
for (uint i = 0; i < 15; i++) {
std::string new_cmp_name = "divRem15"+ctx->generate_position_array(aux_dimensions, 1, i);
DivRem_6_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 13 ;
aux_cmp_num += 3;
}
}
{
uint aux_create = 45;
int aux_cmp_num = 165+ctx_index+1;
uint csoffset = mySignalStart+675;
uint aux_dimensions[1] = {15};
for (uint i = 0; i < 15; i++) {
std::string new_cmp_name = "isFizzs"+ctx->generate_position_array(aux_dimensions, 1, i);
IsZero_7_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 3 ;
aux_cmp_num += 1;
}
}
{
uint aux_create = 60;
int aux_cmp_num = 135+ctx_index+1;
uint csoffset = mySignalStart+585;
uint aux_dimensions[1] = {15};
for (uint i = 0; i < 15; i++) {
std::string new_cmp_name = "isBuzzs"+ctx->generate_position_array(aux_dimensions, 1, i);
IsZero_7_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 3 ;
aux_cmp_num += 1;
}
}
{
uint aux_create = 75;
int aux_cmp_num = 150+ctx_index+1;
uint csoffset = mySignalStart+630;
uint aux_dimensions[1] = {15};
for (uint i = 0; i < 15; i++) {
std::string new_cmp_name = "isFizzBuzzs"+ctx->generate_position_array(aux_dimensions, 1, i);
IsZero_7_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 3 ;
aux_cmp_num += 1;
}
}
{
uint aux_create = 90;
int aux_cmp_num = 240+ctx_index+1;
uint csoffset = mySignalStart+960;
uint aux_dimensions[1] = {15};
for (uint i = 0; i < 15; i++) {
std::string new_cmp_name = "muxFizzs"+ctx->generate_position_array(aux_dimensions, 1, i);
Mux1_9_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 8 ;
aux_cmp_num += 2;
}
}
{
uint aux_create = 105;
int aux_cmp_num = 180+ctx_index+1;
uint csoffset = mySignalStart+720;
uint aux_dimensions[1] = {15};
for (uint i = 0; i < 15; i++) {
std::string new_cmp_name = "muxBuzzs"+ctx->generate_position_array(aux_dimensions, 1, i);
Mux1_9_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 8 ;
aux_cmp_num += 2;
}
}
{
uint aux_create = 120;
int aux_cmp_num = 210+ctx_index+1;
uint csoffset = mySignalStart+840;
uint aux_dimensions[1] = {15};
for (uint i = 0; i < 15; i++) {
std::string new_cmp_name = "muxFizzBuzzs"+ctx->generate_position_array(aux_dimensions, 1, i);
Mux1_9_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 8 ;
aux_cmp_num += 2;
}
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[8]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[8]); // line circom 53
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 15)]);
}
{
printf("=== ");
}
{
printf(" ");
}
{
char* temp = Fr_element2str(&lvar[2]);
printf("%s",temp);
delete [] temp;
}
{
printf(" ");
}
{
printf(" ===");
}
{
printf("\n");
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&lvar[2]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
DivRem_2_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 15);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&lvar[2]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
DivRem_3_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 30);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&lvar[2]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
DivRem_6_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 45);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 0);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 0);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 0)]].signalStart + 1]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
IsZero_7_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 60);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 15);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 15);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 15)]].signalStart + 1]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
IsZero_7_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 75);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 30);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 30);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 30)]].signalStart + 1]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
IsZero_7_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 90);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 45);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 45);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 45)]].signalStart + 0]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 90);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[2]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 90);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[10]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 105);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 60);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 60);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 60)]].signalStart + 0]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 105);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 90);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 90);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 90)]].signalStart + 0]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 105);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[11]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 120);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 105);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 105);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 105)]].signalStart + 0]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 120);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[12]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 120);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 75);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 75);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 75)]].signalStart + 0]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux1_9_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 120);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 120);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 120)]].signalStart + 0]);
}
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 75);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 75);
if(Fr_isTrue(&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 75)]].signalStart + 0])){
{
printf("FizzBuzz");
}
{
printf("\n");
}
}else{
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 45);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 45);
if(Fr_isTrue(&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 45)]].signalStart + 0])){
{
printf("Fizz");
}
{
printf("\n");
}
}else{
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 60);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[1])) + 60);
if(Fr_isTrue(&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 60)]].signalStart + 0])){
{
printf("Buzz");
}
{
printf("\n");
}
}else{
{
char* temp = Fr_element2str(&lvar[2]);
printf("%s",temp);
delete [] temp;
}
{
printf("\n");
}
}
}
}
{
printf("out:");
}
{
printf(" ");
}
{
char* temp = Fr_element2str(&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)]);
printf("%s",temp);
delete [] temp;
}
{
printf("\n");
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 53
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[8]); // line circom 53
}
{
printf("============");
}
{
printf("\n");
}
for (uint i = 0; i < 135; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
FizzBuzz_10_create(1,0,ctx,"main",0);
FizzBuzz_10_run(0,ctx);
}

