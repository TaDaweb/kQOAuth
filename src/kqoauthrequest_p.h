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

#include <QString>
#include <QUrl>

class KQOAuthRequestPrivate {

    Q_DECLARE_PUBLIC(KQOAuthRequest);

public:
    KQOAuthRequestPrivate();

    // Helper methods to get the value for the OAuth request.
    QString oauthTimestamp() const;
    QString oauthNonce() const;
    QString oauthSignature() const;

    // Let's define the OAuth keys for the request
    // parameters here.
    static const QString OAUTH_KEY_CONSUMER;
    static const QString OAUTH_KEY_CONSUMER_KEY;
    static const QString OAUTH_KEY_TOKEN;
    static const QString OAUTH_KEY_SIGNATURE_METHOD;
    static const QString OAUTH_KEY_TIMESTAMP;
    static const QString OAUTH_KEY_NONCE;
    static const QString OAUTH_KEY_SIGNATURE;

    QString oauthConsumerKey;
    QString oauthConsumerSecretKey;
    QString oauthSignatureMethod;
    QUrl oauthCallbackUrl;

    // These will be generated by the helper methods
    QString oauthTimestamp_;
    QString oauthNonce_;

    // Q-pointer
    KQOAuthRequest *q_ptr;

};
#endif // KQOAUTHREQUEST_P_H