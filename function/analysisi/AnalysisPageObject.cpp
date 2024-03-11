#include "AnalysisPageObject.h"
#include <analysisi/AnalysisItemData.h>

AnalysisPageObject::AnalysisPageObject(QObject *parent)
    : QObject{parent}
{
    initAllData();
}

void AnalysisPageObject::initAllData()
{
    QStringList allTitleNameList;
    allTitleNameList<<"事件编号"<<"样本来源"<<"病历编号"<<"姓  名"<<"年  龄"<<"社会性别"
                     <<"孕  龄"<<"周"<<"接种日期"<<"采集日期"<<"报告日期"<<"临床诊断"<<"意  见"
                     <<"制片人"<<"阅片及报告打印人"<<"校片人"<<"审核人1"<<"审核人2"
                     <<"妊娠方式"<<"分  析"<<"计  数"<<"事件核型"<<"核型统计";

    QList<ItemTypeEnum> allItemType;
    allItemType<<Type_InputText<<Type_ComboBox<<Type_InputText<<Type_InputText<<Type_InputTextAndComboBox<<Type_ComboBox
                <<Type_InputText<<Type_InputText<<Type_DateButton<<Type_DateButton<<Type_DateButton<<Type_ComboBox<<Type_ComboBox
                <<Type_ComboBox<<Type_ComboBox<<Type_ComboBox<<Type_ComboBox<<Type_ComboBox<<Type_ComboBox<<Type_InputTextAndCheckBox
                <<Type_InputTextAndCheckBox<<Type_InputTextExpand<<Type_InputTextExpand;


    //样本来源
    QStringList sampleSourceList;
    sampleSourceList<<"外周血"<<"羊水"<<"脐血"<<"脐带间充质"<<"绒毛";

    QStringList ageList;
    ageList<<"岁"<<"月"<<"天";

    QStringList sexList ={"男", "女"};

    //临床诊断
    QStringList clinicalDiagnosisList;
    clinicalDiagnosisList<<"继发不孕"<<"原发不孕"<<"继发不育"<<"原发不育"<<"染色体复查"<<"IVF-ET术前"<<"ICSI术前"<<"自然流产查因"<<"CCS-PGD术后"
                          <<"FISH-PGD术后"<<"ICSI术后"<<"PGS术后"<<"复发性流产"<<"习惯性流产"<<"不良孕史"<<"不良妊娠史、生育史"<<"生化妊娠史"
                          <<"胚胎停育查因"<<"原发闭经"<<"继发闭经"<<"小睾查因"<<"极度少弱精症查因"<<"弱畸精子症"<<"阻塞性无精"<<"智低查因"
                          <<"第二性征发育欠佳查因"<<"平衡易位携带者"<<"排除染色体异常"<<"卵巢早衰"<<"宫内妊娠"<<"阴茎短小、藏匿阴茎"
                          <<"原因不明不孕"<<"不孕症"<<"原发不孕、智力低下"<<"先天性白内障";

    //意见
    QStringList opinionList;
    opinionList<<"普通G带未见异常"<<"高分辨G带未见异常"<<"为罗氏易位携带者,可考虑行PGT-SR(FISH)或PGT-SR(NGS),建议来我院看遗传咨询门诊"<<"为克氏征,建议来我院看遗传咨询门诊"
                <<"为21三体综合征,建议来我院看遗传咨询门诊"<<"为平衡易位携带者,可考虑行PGT-SR(FISH)或PGT-SR(NGS),建议来我院看遗传咨询门诊"<<"为嵌合体,建议来我院看遗传咨询门诊"
                <<"为9号染色体次缢痕区臂间倒位,在临床上有争议,按《人类染色体命名的国际体制》属正常多态,与不孕、自然流产及出生缺陷关系不大"<<"为Y染色体倒位,在临床上有争议,按《人类染色体命名的国际体制》属正常多态,与不孕、自然流产及出生缺陷关系不大"
                <<"为47,XY,+mar,建议来我院看遗传咨询门诊"<<"为47,XX,+mar,建议来我院看遗传咨询门诊"<<"为15p+,建议行FISH做进一步检测"
                <<"为母源性平衡易位,建议来我院看遗传咨询门诊"<<"为47,XYY综合征,建议来我院看遗传咨询门诊"
                <<"为47,XXX综合征,建议来我院看遗传咨询门诊"<<"为DSD(性发育异常),建议来我院看遗传咨询门诊"<<"为复杂易位携带者,建议行PGT-SR(NGS),建议来我院看遗传咨询门诊"
                <<"为臂间倒位携带者,可考虑行PGT-SR(FISH)或PGT-SR(NGS),建议来我院看遗传咨询门诊"<<"为臂内倒位携带者,可考虑行PGT-SR(FISH)或PGT-SR(NGS),建议来我院看遗传咨询门诊";

    //制片人
    QStringList producerList;
    producerList<<"张俊、熊巧媛、郭永腾"<<"郑清、聂双双、刘鑫"<<"莫兰香、杨强、肖敦"<<"张桦、王银辉";

    //阅片及报告打印人
    QStringList readerReportList;
    readerReportList<<"王银辉"<<"张俊"<<"王琪"<<"郑清"<<"张桦"<<"刘鑫"<<"莫兰香"<<"杨强"
                       <<"佘雪妮"<<"肖敦"<<"郭永腾"<<"谢春波"<<"张晴"<<"徐芳"<<"谭沁"<<"聂双双"<<"易朵"<<"熊巧媛"
                     <<"宋璇"<<"张桦、王银辉"<<"王银辉、张桦";

    //校片人
    QStringList schoolFilmmaker;
    schoolFilmmaker<<"张俊"<<"杨强"<<"郑清"<<"狄玉芬"<<"谭跃球 研究员";

    //审核人1
    QStringList reviewer1List;
    reviewer1List<<"谭跃球 研究员"<<"钟昌高 副主任医师"<<"张俊"<<"郑清"<<"张桦";

    //审核人2
    QStringList reviewer2List;
    reviewer2List<<"胡浩 副主任医师";

    //妊娠方式;
    QStringList pregnancyModeList;
    pregnancyModeList<<"自然妊娠"<<"IVF术后"<<"ICSI术后"<<"PGT术后"<<"PGT-A术后"<<"PGT-M术后"
                      <<"PGT-SR(NGS)术后"<<"PGS术后";

    int titleLen = allTitleNameList.size();
    for( int i = 0; i < titleLen; i++ )
    {
        AnalysisItemData * itemData = new AnalysisItemData(this);

        QString titleName = allTitleNameList.at(i) ;
        itemData->setTitleName( titleName );
        itemData->setItemType(allItemType.at(i));

        if( titleName == "样本来源")
        {
            //样本来源
            itemData->setDataList( sampleSourceList );
            itemData->setTextContent( sampleSourceList.at(0) );
        }
        else if ( titleName == "年  龄" )
        {
            itemData->setDataList( ageList );
            itemData->setTextContent( ageList.at(0) );
        }
        else if( titleName == "社会性别" )
        {
            itemData->setDataList( sexList );
            itemData->setTextContent( sexList.at(0) );
        }
        else if( titleName == "临床诊断" )
        {
            itemData->setDataList( clinicalDiagnosisList );
            itemData->setTextContent( clinicalDiagnosisList.at(0) );
        }
        else if( titleName == "意  见" )
        {
            itemData->setDataList( opinionList );
            itemData->setTextContent( opinionList.at(0) );
        }
        else if( titleName == "制片人")
        {
            itemData->setDataList( producerList );
            itemData->setTextContent( producerList.at(0) );
        }
        else if( titleName == "阅片及报告打印人" )
        {
            itemData->setDataList( readerReportList );
            itemData->setTextContent( readerReportList.at(0) );
        }
        else if ( titleName == "校片人")
        {
            itemData->setDataList( schoolFilmmaker );
            itemData->setTextContent( schoolFilmmaker.at(0) );
        }
        else if ( titleName == "审核人1")
        {
            itemData->setDataList( reviewer1List );
            itemData->setTextContent( reviewer1List.at(0) );
        }
        else if ( titleName == "审核人2")
        {
            itemData->setDataList( reviewer2List );
            itemData->setTextContent( reviewer2List.at(0) );
        }
        else if ( titleName == "妊娠方式")
        {
            itemData->setDataList( pregnancyModeList );
            itemData->setTextContent( pregnancyModeList.at(0) );
        }

        m_itemObjectModel.append( itemData );
    }

    emit itemObjectModelChanged();
}

QVariant AnalysisPageObject::itemObjectModel() const
{
    return QVariant::fromValue( m_itemObjectModel );
}
