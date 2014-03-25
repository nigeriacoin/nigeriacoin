#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("nigeriacoin://NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("nigeriacoin:NTeTSrWwYVTPuspGJq2bdLbdzj1PSMvBg6?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
