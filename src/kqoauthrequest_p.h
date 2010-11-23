/**
 * KQOAuth - An OAuth authentication library for Qt.
 *
 * Author: Johan Paul (johan.paul@gmail.com)
 *         http://www.johanpaul.com
 *
 *  KQOAuth is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  KQOAuth is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with KQOAuth.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef KQOAUTHREQUEST_P_H
#define KQOAUTHREQUEST_P_H
#include "kqoauthrequest.h"
#include <QString>
#include <QUrl>
#include <QMap>
#include <QPair>
#include <QMultiMap>

class KQOAuthRequestPrivate {    

public:
    KQOAuthRequestPrivate();
    ~KQOAuthRequestPrivate();

    // Helper methods to get the values for the OAuth request parameters.
    QString oauthTimestamp() const;
    QString oauthNonce() const;
    QString oauthSignature();

    // Utility methods for making the request happen.
    void prepareRequest();
    void signRequest();
    bool validateRequest() const;
    QByteArray requestBaseString();
    QByteArray encodedParamaterList(const QList< QPair<QString, QString> > &requestParameters);
    void insertAdditionalParams(QList< QPair<QString, QString> > &requestParams);
    void insertPostBody();
    QByteArray requestBody() const;


    // Let's define the OAuth keys for the request
    // parameters here.
    static const QString OAUTH_KEY_CONSUMER;
    static const QString OAUTH_KEY_CONSUMER_KEY;
    static const QString OAUTH_KEY_TOKEN;
    static const QString OAUTH_KEY_SIGNATURE_METHOD;
    static const QString OAUTH_KEY_TOKEN_SECRET;
    static const QString OAUTH_KEY_TIMESTAMP;
    static const QString OAUTH_KEY_NONCE;
    static const QString OAUTH_KEY_SIGNATURE;
    static const QString OAUTH_KEY_CALLBACK;
    static const QString OAUTH_KEY_VERSION;
    static const QString OAUTH_KEY_VERIFIER;

    QUrl oauthRequestEndpoint;
    KQOAuthRequest::RequestHttpMethod oauthHttpMethod;
    QString oauthHttpMethodString;
    QString oauthConsumerKey;
    QString oauthConsumerSecretKey;
    QString oauthToken;
    QString oauthTokenSecret;
    QString oauthSignatureMethod;
    QUrl oauthCallbackUrl;
    QString oauthVersion;
    QString oauthVerifier;

    // These will be generated by the helper methods
    QString oauthTimestamp_;
    QString oauthNonce_;

    // User specified additional parameters needed for the request.
    QMultiMap<QString, QString> additionalParams;

    // Optional body for a POST request.
    // This is usually used when doing the authorized request to the service.
//     QMultiMap<QString, QString> postBody;
     // The raw POST body content as given to the HTTP request.
     QByteArray postBodyContent;

    // All the parameters associated with this request. These parameters
    // are used in the "Authorized" header of the HTTP request.
    QList< QPair<QString, QString> > requestParameters;

    KQOAuthRequest::RequestType requestType;    

};
#endif // KQOAUTHREQUEST_P_H
